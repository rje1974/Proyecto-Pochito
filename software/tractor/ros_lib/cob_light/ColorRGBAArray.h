#ifndef _ROS_cob_light_ColorRGBAArray_h
#define _ROS_cob_light_ColorRGBAArray_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"

namespace cob_light
{

  class ColorRGBAArray : public ros::Msg
  {
    public:
      uint32_t colors_length;
      typedef std_msgs::ColorRGBA _colors_type;
      _colors_type st_colors;
      _colors_type * colors;

    ColorRGBAArray():
      colors_length(0), colors(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->colors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->colors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->colors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->colors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->colors_length);
      for( uint32_t i = 0; i < colors_length; i++){
      offset += this->colors[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t colors_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      colors_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->colors_length);
      if(colors_lengthT > colors_length)
        this->colors = (std_msgs::ColorRGBA*)realloc(this->colors, colors_lengthT * sizeof(std_msgs::ColorRGBA));
      colors_length = colors_lengthT;
      for( uint32_t i = 0; i < colors_length; i++){
      offset += this->st_colors.deserialize(inbuffer + offset);
        memcpy( &(this->colors[i]), &(this->st_colors), sizeof(std_msgs::ColorRGBA));
      }
     return offset;
    }

    const char * getType(){ return "cob_light/ColorRGBAArray"; };
    const char * getMD5(){ return "8a8aae411a07648ba08dd6bedf519336"; };

  };

}
#endif