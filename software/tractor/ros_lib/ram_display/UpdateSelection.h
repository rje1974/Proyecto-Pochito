#ifndef _ROS_SERVICE_UpdateSelection_h
#define _ROS_SERVICE_UpdateSelection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_display
{

static const char UPDATESELECTION[] = "ram_display/UpdateSelection";

  class UpdateSelectionRequest : public ros::Msg
  {
    public:
      uint32_t selected_poses_length;
      typedef ram_msgs::AdditiveManufacturingPose _selected_poses_type;
      _selected_poses_type st_selected_poses;
      _selected_poses_type * selected_poses;
      typedef bool _temporary_type;
      _temporary_type temporary;

    UpdateSelectionRequest():
      selected_poses_length(0), selected_poses(NULL),
      temporary(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->selected_poses_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->selected_poses_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->selected_poses_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->selected_poses_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->selected_poses_length);
      for( uint32_t i = 0; i < selected_poses_length; i++){
      offset += this->selected_poses[i].serialize(outbuffer + offset);
      }
      union {
        bool real;
        uint8_t base;
      } u_temporary;
      u_temporary.real = this->temporary;
      *(outbuffer + offset + 0) = (u_temporary.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->temporary);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t selected_poses_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      selected_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      selected_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      selected_poses_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->selected_poses_length);
      if(selected_poses_lengthT > selected_poses_length)
        this->selected_poses = (ram_msgs::AdditiveManufacturingPose*)realloc(this->selected_poses, selected_poses_lengthT * sizeof(ram_msgs::AdditiveManufacturingPose));
      selected_poses_length = selected_poses_lengthT;
      for( uint32_t i = 0; i < selected_poses_length; i++){
      offset += this->st_selected_poses.deserialize(inbuffer + offset);
        memcpy( &(this->selected_poses[i]), &(this->st_selected_poses), sizeof(ram_msgs::AdditiveManufacturingPose));
      }
      union {
        bool real;
        uint8_t base;
      } u_temporary;
      u_temporary.base = 0;
      u_temporary.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->temporary = u_temporary.real;
      offset += sizeof(this->temporary);
     return offset;
    }

    const char * getType(){ return UPDATESELECTION; };
    const char * getMD5(){ return "9450bad3668c4bcf9b40486134a2c4c1"; };

  };

  class UpdateSelectionResponse : public ros::Msg
  {
    public:

    UpdateSelectionResponse()
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

    const char * getType(){ return UPDATESELECTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class UpdateSelection {
    public:
    typedef UpdateSelectionRequest Request;
    typedef UpdateSelectionResponse Response;
  };

}
#endif
