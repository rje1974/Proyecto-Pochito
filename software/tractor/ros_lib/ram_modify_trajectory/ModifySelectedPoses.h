#ifndef _ROS_SERVICE_ModifySelectedPoses_h
#define _ROS_SERVICE_ModifySelectedPoses_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char MODIFYSELECTEDPOSES[] = "ram_modify_trajectory/ModifySelectedPoses";

  class ModifySelectedPosesRequest : public ros::Msg
  {
    public:
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      typedef ram_msgs::AdditiveManufacturingPose _pose_reference_type;
      _pose_reference_type pose_reference;
      typedef bool _pose_type;
      _pose_type pose;
      typedef bool _polygon_start_type;
      _polygon_start_type polygon_start;
      typedef bool _polygon_end_type;
      _polygon_end_type polygon_end;
      typedef bool _movement_type_type;
      _movement_type_type movement_type;
      typedef bool _approach_type_type;
      _approach_type_type approach_type;
      typedef bool _blend_radius_type;
      _blend_radius_type blend_radius;
      typedef bool _speed_type;
      _speed_type speed;
      typedef bool _laser_power_type;
      _laser_power_type laser_power;
      typedef bool _feed_rate_type;
      _feed_rate_type feed_rate;

    ModifySelectedPosesRequest():
      poses_length(0), poses(NULL),
      pose_reference(),
      pose(0),
      polygon_start(0),
      polygon_end(0),
      movement_type(0),
      approach_type(0),
      blend_radius(0),
      speed(0),
      laser_power(0),
      feed_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->poses_length);
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->poses[i].serialize(outbuffer + offset);
      }
      offset += this->pose_reference.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pose;
      u_pose.real = this->pose;
      *(outbuffer + offset + 0) = (u_pose.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pose);
      union {
        bool real;
        uint8_t base;
      } u_polygon_start;
      u_polygon_start.real = this->polygon_start;
      *(outbuffer + offset + 0) = (u_polygon_start.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->polygon_start);
      union {
        bool real;
        uint8_t base;
      } u_polygon_end;
      u_polygon_end.real = this->polygon_end;
      *(outbuffer + offset + 0) = (u_polygon_end.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->polygon_end);
      union {
        bool real;
        uint8_t base;
      } u_movement_type;
      u_movement_type.real = this->movement_type;
      *(outbuffer + offset + 0) = (u_movement_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->movement_type);
      union {
        bool real;
        uint8_t base;
      } u_approach_type;
      u_approach_type.real = this->approach_type;
      *(outbuffer + offset + 0) = (u_approach_type.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->approach_type);
      union {
        bool real;
        uint8_t base;
      } u_blend_radius;
      u_blend_radius.real = this->blend_radius;
      *(outbuffer + offset + 0) = (u_blend_radius.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->blend_radius);
      union {
        bool real;
        uint8_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        bool real;
        uint8_t base;
      } u_laser_power;
      u_laser_power.real = this->laser_power;
      *(outbuffer + offset + 0) = (u_laser_power.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->laser_power);
      union {
        bool real;
        uint8_t base;
      } u_feed_rate;
      u_feed_rate.real = this->feed_rate;
      *(outbuffer + offset + 0) = (u_feed_rate.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->feed_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->poses_length);
      if(poses_lengthT > poses_length)
        this->poses = (ram_msgs::AdditiveManufacturingPose*)realloc(this->poses, poses_lengthT * sizeof(ram_msgs::AdditiveManufacturingPose));
      poses_length = poses_lengthT;
      for( uint32_t i = 0; i < poses_length; i++){
      offset += this->st_poses.deserialize(inbuffer + offset);
        memcpy( &(this->poses[i]), &(this->st_poses), sizeof(ram_msgs::AdditiveManufacturingPose));
      }
      offset += this->pose_reference.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_pose;
      u_pose.base = 0;
      u_pose.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->pose = u_pose.real;
      offset += sizeof(this->pose);
      union {
        bool real;
        uint8_t base;
      } u_polygon_start;
      u_polygon_start.base = 0;
      u_polygon_start.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->polygon_start = u_polygon_start.real;
      offset += sizeof(this->polygon_start);
      union {
        bool real;
        uint8_t base;
      } u_polygon_end;
      u_polygon_end.base = 0;
      u_polygon_end.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->polygon_end = u_polygon_end.real;
      offset += sizeof(this->polygon_end);
      union {
        bool real;
        uint8_t base;
      } u_movement_type;
      u_movement_type.base = 0;
      u_movement_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->movement_type = u_movement_type.real;
      offset += sizeof(this->movement_type);
      union {
        bool real;
        uint8_t base;
      } u_approach_type;
      u_approach_type.base = 0;
      u_approach_type.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->approach_type = u_approach_type.real;
      offset += sizeof(this->approach_type);
      union {
        bool real;
        uint8_t base;
      } u_blend_radius;
      u_blend_radius.base = 0;
      u_blend_radius.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->blend_radius = u_blend_radius.real;
      offset += sizeof(this->blend_radius);
      union {
        bool real;
        uint8_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        bool real;
        uint8_t base;
      } u_laser_power;
      u_laser_power.base = 0;
      u_laser_power.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->laser_power = u_laser_power.real;
      offset += sizeof(this->laser_power);
      union {
        bool real;
        uint8_t base;
      } u_feed_rate;
      u_feed_rate.base = 0;
      u_feed_rate.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->feed_rate = u_feed_rate.real;
      offset += sizeof(this->feed_rate);
     return offset;
    }

    const char * getType(){ return MODIFYSELECTEDPOSES; };
    const char * getMD5(){ return "62f4b3540ae5702b17a05444889b43ea"; };

  };

  class ModifySelectedPosesResponse : public ros::Msg
  {
    public:

    ModifySelectedPosesResponse()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return MODIFYSELECTEDPOSES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ModifySelectedPoses {
    public:
    typedef ModifySelectedPosesRequest Request;
    typedef ModifySelectedPosesResponse Response;
  };

}
#endif
