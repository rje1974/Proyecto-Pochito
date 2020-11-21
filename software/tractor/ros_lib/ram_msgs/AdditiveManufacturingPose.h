#ifndef _ROS_ram_msgs_AdditiveManufacturingPose_h
#define _ROS_ram_msgs_AdditiveManufacturingPose_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "uuid_msgs/UniqueID.h"
#include "geometry_msgs/Pose.h"
#include "ram_msgs/AdditiveManufacturingParams.h"

namespace ram_msgs
{

  class AdditiveManufacturingPose : public ros::Msg
  {
    public:
      typedef uuid_msgs::UniqueID _unique_id_type;
      _unique_id_type unique_id;
      typedef geometry_msgs::Pose _pose_type;
      _pose_type pose;
      typedef uint64_t _layer_level_type;
      _layer_level_type layer_level;
      typedef uint64_t _layer_index_type;
      _layer_index_type layer_index;
      typedef bool _polygon_start_type;
      _polygon_start_type polygon_start;
      typedef bool _polygon_end_type;
      _polygon_end_type polygon_end;
      typedef bool _entry_pose_type;
      _entry_pose_type entry_pose;
      typedef bool _exit_pose_type;
      _exit_pose_type exit_pose;
      typedef ram_msgs::AdditiveManufacturingParams _params_type;
      _params_type params;

    AdditiveManufacturingPose():
      unique_id(),
      pose(),
      layer_level(0),
      layer_index(0),
      polygon_start(0),
      polygon_end(0),
      entry_pose(0),
      exit_pose(0),
      params()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->unique_id.serialize(outbuffer + offset);
      offset += this->pose.serialize(outbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_layer_level;
      u_layer_level.real = this->layer_level;
      *(outbuffer + offset + 0) = (u_layer_level.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_layer_level.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_layer_level.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_layer_level.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layer_level);
      union {
        uint64_t real;
        uint32_t base;
      } u_layer_index;
      u_layer_index.real = this->layer_index;
      *(outbuffer + offset + 0) = (u_layer_index.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_layer_index.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_layer_index.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_layer_index.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layer_index);
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
      } u_entry_pose;
      u_entry_pose.real = this->entry_pose;
      *(outbuffer + offset + 0) = (u_entry_pose.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->entry_pose);
      union {
        bool real;
        uint8_t base;
      } u_exit_pose;
      u_exit_pose.real = this->exit_pose;
      *(outbuffer + offset + 0) = (u_exit_pose.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->exit_pose);
      offset += this->params.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->unique_id.deserialize(inbuffer + offset);
      offset += this->pose.deserialize(inbuffer + offset);
      union {
        uint64_t real;
        uint32_t base;
      } u_layer_level;
      u_layer_level.base = 0;
      u_layer_level.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_layer_level.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_layer_level.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_layer_level.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->layer_level = u_layer_level.real;
      offset += sizeof(this->layer_level);
      union {
        uint64_t real;
        uint32_t base;
      } u_layer_index;
      u_layer_index.base = 0;
      u_layer_index.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_layer_index.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_layer_index.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_layer_index.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->layer_index = u_layer_index.real;
      offset += sizeof(this->layer_index);
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
      } u_entry_pose;
      u_entry_pose.base = 0;
      u_entry_pose.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->entry_pose = u_entry_pose.real;
      offset += sizeof(this->entry_pose);
      union {
        bool real;
        uint8_t base;
      } u_exit_pose;
      u_exit_pose.base = 0;
      u_exit_pose.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->exit_pose = u_exit_pose.real;
      offset += sizeof(this->exit_pose);
      offset += this->params.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "ram_msgs/AdditiveManufacturingPose"; };
    const char * getMD5(){ return "7311fd6e5482cdbfc51ac2fe0baae490"; };

  };

}
#endif