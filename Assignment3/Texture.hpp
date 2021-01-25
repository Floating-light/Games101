//
// Created by LEI XU on 4/27/19.
//

#ifndef RASTERIZER_TEXTURE_H
#define RASTERIZER_TEXTURE_H
#include "global.hpp"
#include <Eigen/Eigen>
#include <opencv2/opencv.hpp>
class Texture{
private:
    cv::Mat image_data;

public:
    Texture(const std::string& name)
    {
        image_data = cv::imread(name);
        cv::cvtColor(image_data, image_data, cv::COLOR_RGB2BGR);
        width = image_data.cols;
        height = image_data.rows;
    }

    int width, height;

    Eigen::Vector3f getColor(float u, float v)
    {
        u = u < 0 ? 0 : u;
        auto u_img = u * width;
        auto v_img = (1 - v) * height;
        auto color = image_data.at<cv::Vec3b>(v_img, u_img);
        return Eigen::Vector3f(color[0], color[1], color[2]);
    }

    Eigen::Vector3f getColor_hide(float u, float v)
    {
        u = u < 0 ? 0 : u;
        float u_img = u * width;
        float v_img = (1 - v) * height;
        float l_w = int(u_img);
        float b_w = int(u_img) + 1;
        float l_h = int(v_img);
        float b_h = int(v_img) + 1;

        if (b_w > width || b_h > height)
        {
            return getColor_hide(u, v);
        }

        auto row1 = image_data.at<cv::Vec3b>(l_h, l_w) * (u_img - l_w) + (1 - u_img + l_w) * image_data.at<cv::Vec3b>(l_h, b_w);
        auto row2 = image_data.at<cv::Vec3b>(b_h, l_w) * (u_img - l_w) + (1 - u_img + l_w) * image_data.at<cv::Vec3b>(b_h, b_w);

        auto result = row1 * (v_img - l_h) + (1 - v_img + l_h) * row2;
        return Eigen::Vector3f(result[0], result[1], result[2]);
    }
};
#endif //RASTERIZER_TEXTURE_H
