#ifndef _ROS_SERVICE_ReflectSelectedPoses_h
#define _ROS_SERVICE_ReflectSelectedPoses_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Vector3.h"
#include "geometry_msgs/Point.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char REFLECTSELECTEDPOSES[] = "ram_modify_trajectory/ReflectSelectedPoses";

  class ReflectSelectedPosesRequest : public ros::Msg
  {
    public:
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;
      typedef geometry_msgs::Point _point_on_plane_type;
      _point_on_plane_type point_on_plane;
      typedef geometry_msgs::Vector3 _normal_vector_type;
      _normal_vector_type normal_vector;

    ReflectSelectedPosesRequest():
      poses_length(0), poses(NULL),
      point_on_plane(),
      normal_vector()
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
      offset += this->point_on_plane.serialize(outbuffer + offset);
      offset += this->normal_vector.serialize(outbuffer + offset);
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
      offset += this->point_on_plane.deserialize(inbuffer + offset);
      offset += this->normal_vector.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return REFLECTSELECTEDPOSES; };
    const char * getMD5(){ return "a94b18fb29d0d54bf196d05188b7c99c"; };

  };

  class ReflectSelectedPosesResponse : public ros::Msg
  {
    public:

    ReflectSelectedPosesResponse()
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

    const char * getType(){ return REFLECTSELECTEDPOSES; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class ReflectSelectedPoses {
    public:
    typedef ReflectSelectedPosesRequest Request;
    typedef ReflectSelectedPosesResponse Response;
  };

}
#endif
