#ifndef _ROS_cob_phidgets_AnalogSensor_h
#define _ROS_cob_phidgets_AnalogSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_phidgets
{

  class AnalogSensor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t uri_length;
      typedef char* _uri_type;
      _uri_type st_uri;
      _uri_type * uri;
      uint32_t value_length;
      typedef int16_t _value_type;
      _value_type st_value;
      _value_type * value;

    AnalogSensor():
      header(),
      uri_length(0), uri(NULL),
      value_length(0), value(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->uri_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->uri_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->uri_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->uri_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->uri_length);
      for( uint32_t i = 0; i < uri_length; i++){
      uint32_t length_urii = strlen(this->uri[i]);
      varToArr(outbuffer + offset, length_urii);
      offset += 4;
      memcpy(outbuffer + offset, this->uri[i], length_urii);
      offset += length_urii;
      }
      *(outbuffer + offset + 0) = (this->value_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->value_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->value_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->value_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->value_length);
      for( uint32_t i = 0; i < value_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_valuei;
      u_valuei.real = this->value[i];
      *(outbuffer + offset + 0) = (u_valuei.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_valuei.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->value[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t uri_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      uri_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      uri_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      uri_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->uri_length);
      if(uri_lengthT > uri_length)
        this->uri = (char**)realloc(this->uri, uri_lengthT * sizeof(char*));
      uri_length = uri_lengthT;
      for( uint32_t i = 0; i < uri_length; i++){
      uint32_t length_st_uri;
      arrToVar(length_st_uri, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_uri; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_uri-1]=0;
      this->st_uri = (char *)(inbuffer + offset-1);
      offset += length_st_uri;
        memcpy( &(this->uri[i]), &(this->st_uri), sizeof(char*));
      }
      uint32_t value_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      value_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->value_length);
      if(value_lengthT > value_length)
        this->value = (int16_t*)realloc(this->value, value_lengthT * sizeof(int16_t));
      value_length = value_lengthT;
      for( uint32_t i = 0; i < value_length; i++){
      union {
        int16_t real;
        uint16_t base;
      } u_st_value;
      u_st_value.base = 0;
      u_st_value.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_st_value.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_value = u_st_value.real;
      offset += sizeof(this->st_value);
        memcpy( &(this->value[i]), &(this->st_value), sizeof(int16_t));
      }
     return offset;
    }

    const char * getType(){ return "cob_phidgets/AnalogSensor"; };
    const char * getMD5(){ return "b52a946d34a1d251ef4461cdadfa70ae"; };

  };

}
#endif