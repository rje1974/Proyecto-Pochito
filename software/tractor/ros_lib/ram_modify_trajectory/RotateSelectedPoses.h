#ifndef _ROS_SERVICE_RotateSelectedPoses_h
#define _ROS_SERVICE_RotateSelectedPoses_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Point.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char ROTATESELECTEDPOSES[] = "ram_modify_trajectory/RotateSelectedPoses";

  class RotateSelectedPosesRequest : public ros::Msg
  {
    public:
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      typedef float _rotation_angle_type;
      _rotation_angle_type rotation_angle;
      typedef geometry_msgs::Point _center_of_rotation_type;
      _center_of_rotation_type center_of_rotation;

    RotateSelectedPosesRequest():
      poses_length(0), poses(NULL),
      rotation_angle(0),
      center_of_rotation()
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
      offset += serializeAvrFloat64(outbuffer + offset, this->rotation_angle);
      offset += this->center_of_rotation.serialize(outbuffer + offset);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rotation_angle));
      offset += this->center_of_rotation.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return ROTATESELECTEDPOSES; };
    const char * getMD5(){ return "360a6a9b4f9b0372d8fd6a4c1a376abf"; };

  };

  class RotateSelectedPosesResponse : public ros::Msg
  {
    public:

    RotateSelectedPosesResponse()
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

    const char * getType(){ return ROTATESELECTEDPOSES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class RotateSelectedPoses {
    public:
    typedef RotateSelectedPosesRequest Request;
    typedef RotateSelectedPosesResponse Response;
  };

}
#endif
