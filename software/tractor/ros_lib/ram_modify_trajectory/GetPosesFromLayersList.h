#ifndef _ROS_SERVICE_GetPosesFromLayersList_h
#define _ROS_SERVICE_GetPosesFromLayersList_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char GETPOSESFROMLAYERSLIST[] = "ram_modify_trajectory/GetPosesFromLayersList";

  class GetPosesFromLayersListRequest : public ros::Msg
  {
    public:
      uint32_t layer_level_list_length;
      typedef uint32_t _layer_level_list_type;
      _layer_level_list_type st_layer_level_list;
      _layer_level_list_type * layer_level_list;

    GetPosesFromLayersListRequest():
      layer_level_list_length(0), layer_level_list(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->layer_level_list_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->layer_level_list_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->layer_level_list_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->layer_level_list_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layer_level_list_length);
      for( uint32_t i = 0; i < layer_level_list_length; i++){
      *(outbuffer + offset + 0) = (this->layer_level_list[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->layer_level_list[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->layer_level_list[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->layer_level_list[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layer_level_list[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t layer_level_list_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      layer_level_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      layer_level_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      layer_level_list_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->layer_level_list_length);
      if(layer_level_list_lengthT > layer_level_list_length)
        this->layer_level_list = (uint32_t*)realloc(this->layer_level_list, layer_level_list_lengthT * sizeof(uint32_t));
      layer_level_list_length = layer_level_list_lengthT;
      for( uint32_t i = 0; i < layer_level_list_length; i++){
      this->st_layer_level_list =  ((uint32_t) (*(inbuffer + offset)));
      this->st_layer_level_list |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_layer_level_list |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_layer_level_list |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_layer_level_list);
        memcpy( &(this->layer_level_list[i]), &(this->st_layer_level_list), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return GETPOSESFROMLAYERSLIST; };
    const char * getMD5(){ return "679d154e8037a273f18c70341905eba3"; };

  };

  class GetPosesFromLayersListResponse : public ros::Msg
  {
    public:
      uint32_t poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _poses_type;
      _poses_type st_poses;
      _poses_type * poses;

    GetPosesFromLayersListResponse():
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

    const char * getType(){ return GETPOSESFROMLAYERSLIST; };
    const char * getMD5(){ return "f6ccb95f5843381777dba4bb5d0e3f7d"; };

  };

  class GetPosesFromLayersList {
    public:
    typedef GetPosesFromLayersListRequest Request;
    typedef GetPosesFromLayersListResponse Response;
  };

}
#endif
