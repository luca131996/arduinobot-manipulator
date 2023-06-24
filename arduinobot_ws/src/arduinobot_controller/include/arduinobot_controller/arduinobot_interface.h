#pragma once

#include <hardware_interface/robot_hw.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/joint_command_interface.h>
#include <controller_manager/controller_manager.h>
#include <ros/ros.h>
#include "arduinobot_controller/AnglesConverter.h"
#include <std_msgs/Uint16MultiArray.h>
#include <vector>
#include <boost/scoped_ptr.hpp>

class ArduinobotInterface : public hardware_interface::RobotHw
{
public:
    ArduinobotInterface(ros::NodeHandle&);
    void update(const ros::TimerEvent& e); // implementa la logica di controllo
    void read(); // legge lo stato dei motori
    void write(ros::Duration elapsed_time); // scrive i risultati su arduino

private:
    ros::NodeHandle nh;
    ros::NodeHandle pnh;
    ros::Duration elapsed_time; // durata in secondi dall'ultima esecuzione del loop di controllo
    ros::Duration update_freq; // frequenza con cui chiamare la funzione di controllo
    ros::Timer looper;
    ros::Publisher hardware_pub;
    ros::ServiceClient hardware_srv;
    hardware_interface::JointStateInterface joint_state_interface
    hardware_interface::PositionJointInterface joint_position_interface
    boost::shared_ptr<controller_manager::ControllerManager> controller_manager;
    std::vector<double> cmd; // comando da mandare a ciascun giunto
    std::vector<double> pos; // posizione
    std::vector<double> vel; // velocità
    std::vector<double> eff; // effort di controllo
    std::vector<std::string> names; // nomi di tutti i giunti 

};