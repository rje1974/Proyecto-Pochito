#ifndef _ROS_SERVICE_SetDataRate_h
#define _ROS_SERVICE_SetDataRate_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_phidgets
{

static const char SETDATARATE[] = "cob_phidgets/SetDataRate";

  class SetDataRateRequest : public ros::Msg
  {
    public:
      typedef int8_t _index_type;
      _index_type index;
      typedef uint16_t _data_rate_type;
      _data_rate_type data_rate;

    SetDataRateRequest():
      index(0),
      data_rate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.real = this->index;
      *(outbuffer + offset + 0) = (u_index.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->index);
      *(outbuffer + offset + 0) = (this->data_rate >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_rate >> (8 * 1)) & 0xFF;
      offset += sizeof(this->data_rate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_index;
      u_index.base = 0;
      u_index.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->index = u_index.real;
      offset += sizeof(this->index);
      this->data_rate =  ((uint16_t) (*(inbuffer + offset)));
      this->data_rate |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->data_rate);
     return offset;
    }

    const char * getType(){ return SETDATARATE; };
    const char * getMD5(){ return "2fe4d4dafc6b478c7e506a02543a3197"; };

  };

  class SetDataRateResponse : public ros::Msg
  {
    public:

    SetDataRateResponse()
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

    const char * getType(){ return SETDATARATE; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class SetDataRate {
    public:
    typedef SetDataRateRequest Request;
    typedef SetDataRateResponse Response;
  };

}
#endif
