# JanusROS-Videoroom

## 1. Summary

  <p align="center">
    <img width="700" src="https://user-images.githubusercontent.com/80872528/163091121-6cb8eca9-82bc-4a72-974d-c9bbefd36dd0.png">
  </p>

  * ROS image publisher : Publishing ROS Image
  * ROS_stream converter : Subscribing ROS Image & Converting ROS Image into numpy data & Sending data
  * Janus server with docker
  * Observation system : browser


## 2. documentation

   ### a) ROS image publisher
        
    Publish image with ROS
    
  ```
  In package

  $ catkin_make
  $ source ./devel/setup.bash
  $ rosrun ros_opencv_pub ros_opencv_pub
  ```
    
  
   ### b) ROS_stream converter

  * Peer connection with Janus server
  * Convert ROS image into numpy data 
  * After subscribing ROS image, convert it to numpy data
  * Send data to a peer

  ```
  In package
  
  $ conda activate aio2 
    (I used my own virtual env of python3)
    
  $ catkin_make
  $ source ./devel/setup.bash
  $ rosrun test janus.py
  ```
  
  
  ### c) Janus server with docker

  prepare to receive signalling from peers 

  ```
  $ sudo docker pull canyan/janus-gateway:latest

  $ docker run -itd -p 8088:8088 -p 8000:8000 --name janus janus /bin/bash -c "/root/janus-gateway/run_janus.sh;/bin/sh"        
  ```

  Browser address : http://127.0.0.1:8000/videoroomtest.html

  [More information : janus-gateway](https://github.com/meetecho/janus-gateway)
  
  

  ### d) Observation system

  You can check the ROS-Janus stream through browser.

  <p align="center">
      <img width="700" src="https://user-images.githubusercontent.com/80872528/163103632-c08d37ed-72af-4445-99d1-daac8609d41e.png">
  </p>

## 3. More feature

  ### videoroom_create.py

    It helps to create new video room. You can join the room with specific url. 

    ex) http://127.0.0.1:8000/videoroomtest.html?room=9999



  ### roomlist.py 

    It shows the room list.


## 4. Reference
  * https://janus.conf.meetecho.com/docs/videoroom.html
  * https://janus.conf.meetecho.com/docs/JS.html
  * https://github.com/aiortc/aiortc/tree/28cf22c2a82136784cc8ece6ca82143afdba5c86/examples/videostream-cli
  * https://github.com/ken107/janus-videoroom-js

Janus API documentation helps how to use and write Janus API with json. 
  
