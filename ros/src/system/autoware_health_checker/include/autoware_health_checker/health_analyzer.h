#ifndef HEALTH_ANALYZER_H_INCLUDED
#define HEALTH_ANALYZER_H_INCLUDED

/*
 * Copyright 2019 Autoware Foundation. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *
 * v1.0 Masaya Kataoka
 */

#include <ros/ros.h>
#include <rosgraph_msgs/TopicStatistics.h>

//headers in Autoware
#include <autoware_system_msgs/SystemStatus.h>

class HealthAnalyzer
{
public:
    HealthAnalyzer(ros::NodeHandle nh, ros::NodeHandle pnh);
    ~HealthAnalyzer();
private:
    ros::Subscriber system_status_sub_;
    ros::Subscriber topic_statistics_sub_;
    ros::NodeHandle nh_;
    ros::NodeHandle pnh_;
    void systemStatusCallback(const autoware_system_msgs::SystemStatus::ConstPtr msg);
    void topicStatisticsCallback(const rosgraph_msgs::TopicStatistics::ConstPtr msg);
};

#endif //HEALTH_ANALYZER_H_INCLUDED