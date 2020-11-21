#ifndef _ROS_SERVICE_EraseSelection_h
#define _ROS_SERVICE_EraseSelection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ram_msgs/AdditiveManufacturingPose.h"

namespace ram_modify_trajectory
{

static const char ERASESELECTION[] = "ram_modify_trajectory/EraseSelection";

  class EraseSelectionRequest : public ros::Msg
  {
    public:

    EraseSelectionRequest()
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

    const char * getType(){ return ERASESELECTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class EraseSelectionResponse : public ros::Msg
  {
    public:
      uint32_t selection_length;
      typedef ram_msgs::AdditiveManufacturingPose _selection_type;
      _selection_type st_selection;
      _selection_type * selection;

    EraseSelectionResponse():
      selection_length(0), selection(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->selection_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->selection_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->selection_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->selection_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->selection_length);
      for( uint32_t i = 0; i < selection_length; i++){
      offset += this->selection[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t selection_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      selection_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      selection_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      selection_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->selection_length);
      if(selection_lengthT > selection_length)
        this->selection = (ram_msgs::AdditiveManufacturingPose*)realloc(this->selection, selection_lengthT * sizeof(ram_msgs::AdditiveManufacturingPose));
      selection_length = selection_lengthT;
      for( uint32_t i = 0; i < selection_length; i++){
      offset += this->st_selection.deserialize(inbuffer + offset);
        memcpy( &(this->selection[i]), &(this->st_selection), sizeof(ram_msgs::AdditiveManufacturingPose));
      }
     return offset;
    }

    const char * getType(){ return ERASESELECTION; };
    const char * getMD5(){ return "f3989c42a49c47ec62020e272d6a406d"; };

  };

  class EraseSelection {
    public:
    typedef EraseSelectionRequest Request;
    typedef EraseSelectionResponse Response;
  };

}
#endif
