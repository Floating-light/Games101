#include "Triangle.hpp"
#include "rasterizer.hpp"
#include <Eigen/Eigen>
#include <iostream>
#include <opencv2/opencv.hpp>

constexpr double MY_PI = 3.1415926;

// 将相机位置标准化
// 位置在原点，上方向在Y轴方向，看向-Z
// 假设相机没有旋转
Eigen::Matrix4f get_view_matrix(Eigen::Vector3f eye_pos)
{
    Eigen::Matrix4f view = Eigen::Matrix4f::Identity();

    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -eye_pos[0], 0, 1, 0, -eye_pos[1], 0, 0, 1,
        -eye_pos[2], 0, 0, 0, 1;

    view = translate * view;

    return view;
}

Eigen::Matrix4f get_model_matrix(float rotation_angle)
{
    Eigen::Matrix4f model = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the model matrix for rotating the triangle around the Z axis.
    // Then return it.
    rotation_angle = rotation_angle * MY_PI / 180.0;
    Eigen::Matrix4f rotation;
    rotation << cos(rotation_angle), -sin(rotation_angle), 0, 0,
        sin(rotation_angle), cos(rotation_angle), 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1;
    
    model = rotation * model;

    return model;
}

Eigen::Matrix4f get_projection_matrix(float eye_fov, float aspect_ratio,
                                      float zNear, float zFar)
{
    // Students will implement this function

    Eigen::Matrix4f projection = Eigen::Matrix4f::Identity();

    // TODO: Implement this function
    // Create the projection matrix for the given parameters.
    // Then return it.

    //透视投影，将视锥范围内的模型挤压到一个立方体中
    Eigen::Matrix4f Mpersp2ortho;
    Mpersp2ortho << zNear, 0, 0, 0,
        0, zNear, 0, 0,
        0, 0, zNear + zFar, -zNear * zFar,
        0, 0,1, 0; // 这个1......
    projection = Mpersp2ortho * projection;

    // 正交投影
    //将一个立方体范围投影到标准立方体[-1,1]^3,
    Eigen::Matrix4f Mortho = Eigen::Matrix4f::Identity();
    float t = zNear * tan((eye_fov*MY_PI/180.0) / 2.0);
    float b = -t;
    float r = t * aspect_ratio;
    float l = -r;
    Eigen::Matrix4f translate;
    translate << 1, 0, 0, -(l + r) / 2,
        0, 1, 0, -(t + b) / 2,
        0, 0, 1, -(zNear + zFar) / 2,
        0, 0, 0, 1;

    Eigen::Matrix4f scale;
    scale << 2.0 / (r - l), 0, 0, 0,
        0, 2.0 / (t - b), 0, 0,
        0, 0, 2.0 / (zNear - zFar), 0,
        0, 0, 0, 1;

    // 先平移，再缩放
    Mortho = scale * (translate * Mortho); //不用括号也行

    projection = Mortho *projection;
    std::cout << projection << std::endl;

    return projection;


    
}

int main(int argc, const char** argv)
{
    // 模型（我们的三角形）旋转的角度
    float angle = 0;
    bool command_line = false;
    std::string filename = "output.png";

    if (argc >= 3) {
        command_line = true;
        angle = std::stof(argv[2]); // -r by default
        if (argc == 4) {
            filename = std::string(argv[3]);
        }
        else
            return 0;
    }

    // 初始化视口大小
    rst::rasterizer r(700, 700);

    // 相机位置
    Eigen::Vector3f eye_pos = {0, 0, 5};

    // 顶点集
    std::vector<Eigen::Vector3f> pos{{2, 0, -2}, {0, 2, -2}, {-2, 0, -2}};

    // 三角形集，对应于顶点集中的点的索引， 三个索引组成一个三角形
    std::vector<Eigen::Vector3i> ind{{0, 1, 2}};

    // 这个顶点集在光栅化器的顶点buffer中的索引
    auto pos_id = r.load_positions(pos);
    // 对应于上面的顶点集，三角形集合在光栅化器的三角形集buffer中的索引
    auto ind_id = r.load_indices(ind);

    int key = 0;
    int frame_count = 0;

    if (command_line) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);
        
        // 模型变换,绕z轴旋转angle
        r.set_model(get_model_matrix(angle));
        // 视图/相机变换
        // 相机位置标准化
        r.set_view(get_view_matrix(eye_pos));

        //投影变换
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);
        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);

        cv::imwrite(filename, image);

        return 0;
    }

    while (key != 27) {
        r.clear(rst::Buffers::Color | rst::Buffers::Depth);

        r.set_model(get_model_matrix(angle));
        r.set_view(get_view_matrix(eye_pos));
        r.set_projection(get_projection_matrix(45, 1, 0.1, 50));

        r.draw(pos_id, ind_id, rst::Primitive::Triangle);

        cv::Mat image(700, 700, CV_32FC3, r.frame_buffer().data());
        image.convertTo(image, CV_8UC3, 1.0f);
        cv::imshow("image", image);
        key = cv::waitKey(10);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          

        std::cout << "frame count: " << frame_count++ << '\n';

        if (key == 'a') {
            angle += 10;
        }
        else if (key == 'd') {
            angle -= 10;
        }
    }

    return 0;
}
