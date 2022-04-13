#include <ros/ros.h>
#include <ros/console.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/highgui/highgui.hpp>
#include <sstream>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/image_encodings.h>
#include <image_transport/image_transport.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ros_opencv_pub1");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("video/test1", 1);

  cv_bridge::CvImage img_bridge;
  sensor_msgs::Image img_msg;

  VideoCapture cap("/home/jskimlab/Desktop/rosvideo/src/ros_opencv_pub/test1.mp4"); // file path

  std::cout << "video prepared" << std::endl;

  	if (!cap.isOpened())
	{
		printf("Can't open the camera");
		return -1;
	}

  Mat img;

  ros::Rate loop_rate(30);

  uint counter = 0;

  std::cout << "Publishing Image" << std::endl;
  while(ros::ok())
  {
    cap >> img;

    if (img.empty())
		{
			printf("empty image");
			return 0;
		}


    std_msgs::Header header; // empty header
    header.seq = counter; // user defined counter
    header.stamp = ros::Time::now(); // time
    img_bridge = cv_bridge::CvImage(header, sensor_msgs::image_encodings::BGR8, img);
    img_bridge.toImageMsg(img_msg); // from cv_bridge to sensor_msgs::Image
    pub.publish(img_msg); // ros::Publisher pub_img = node.advertise<sensor_msgs::Image>("topic", queuesize);


    // cout << counter << " frame published" << endl;
    //ROS_INFO("%d frame published", counter);

    counter++;

    if(waitKey(10)==27) break;
    loop_rate.sleep();
    ros::spinOnce();
  }
  return 0;
}


