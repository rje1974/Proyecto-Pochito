#ifndef _ROS_SERVICE_GetPosesFromLayer_h
#define _ROS_SERVICE_GetPosesFromLayer_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char GETPOSESFROMLAYER[] = "ram_modify_trajectory/GetPosesFromLayer";

  class GetPosesFromLayerRequest : public ros::Msg
  {
    public:
      typedef uint32_t _layer_level_type;
      _layer_level_type layer_level;
      uint32_t index_list_relative_length;
      typedef uint32_t _index_list_relative_type;
      _index_list_relative_type st_index_list_relative;
      _index_list_relative_type * index_list_relative;

    GetPosesFromLayerRequest():
      layer_level(0),
      index_list_relative_length(0), index_list_relative(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->layer_level >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->layer_level >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->layer_level >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->layer_level >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layer_level);
      *(outbuffer + offset + 0) = (this->index_list_relative_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index_list_relative_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->index_list_relative_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->index_list_relative_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index_list_relative_length);
      for( uint32_t i = 0; i < index_list_relative_length; i++){
      *(outbuffer + offset + 0) = (this->index_list_relative[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->index_list_relative[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->index_list_relative[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->index_list_relative[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->index_list_relative[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->layer_level =  ((uint32_t) (*(inbuffer + offset)));
      this->layer_level |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->layer_level |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->layer_level |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->layer_level);
      uint32_t index_list_relative_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      index_list_relative_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      index_list_relative_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      index_list_relative_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->index_list_relative_length);
      if(index_list_relative_lengthT > index_list_relative_length)
        this->index_list_relative = (uint32_t*)realloc(this->index_list_relative, index_list_relative_lengthT * sizeof(uint32_t));
      index_list_relative_length = index_list_relative_lengthT;
      for( uint32_t i = 0; i < index_list_relative_length; i++){
      this->st_index_list_relative =  ((uint32_t) (*(inbuffer + offset)));
      this->st_index_list_relative |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_index_list_relative |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_index_list_relative |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_index_list_relative);
        memcpy( &(this->index_list_relative[i]), &(this->st_index_list_relative), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return GETPOSESFROMLAYER; };
    const char * getMD5(){ return "b2c6373c77653df3017987bf871968bf"; };

  };

  class GetPosesFromLayerResponse : public ros::Msg
  {
    public:
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    GetPosesFromLayerResponse():
      poses_length(0), poses(NULL)
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
     return offset;
    }

    const char * getType(){ return GETPOSESFROMLAYER; };
    const char * getMD5(){ return "f6ccb95f5843381777dba4bb5d0e3f7d"; };

  };

  class GetPosesFromLayer {
    public:
    typedef GetPosesFromLayerRequest Request;
    typedef GetPosesFromLayerResponse Response;
  };

}
#endif
