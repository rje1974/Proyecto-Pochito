#ifndef _ROS_piksi_rtk_msgs_BasePosLlh_h
#define _ROS_piksi_rtk_msgs_BasePosLlh_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace piksi_rtk_msgs
{

  class BasePosLlh : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _lat_type;
      _lat_type lat;
      typedef float _lon_type;
      _lon_type lon;
      typedef float _height_type;
      _height_type height;

    BasePosLlh():
      header(),
      lat(0),
      lon(0),
      height(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->lat);
      offset += serializeAvrFloat64(outbuffer + offset, this->lon);
      offset += serializeAvrFloat64(outbuffer + offset, this->height);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lat));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->lon));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->height));
     return offset;
    }

    const char * getType(){ return "piksi_rtk_msgs/BasePosLlh"; };
    const char * getMD5(){ return "ecab87c8bc63ce24dedbbc842fe1261b"; };

  };

}
#endif