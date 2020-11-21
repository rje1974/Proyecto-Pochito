#ifndef _ROS_cob_phidgets_DigitalSensor_h
#define _ROS_cob_phidgets_DigitalSensor_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_phidgets
{

  class DigitalSensor : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t uri_length;
      typedef char* _uri_type;
      _uri_type st_uri;
      _uri_type * uri;
      uint32_t state_length;
      typedef int8_t _state_type;
      _state_type st_state;
      _state_type * state;

    DigitalSensor():
      header(),
      uri_length(0), uri(NULL),
      state_length(0), state(NULL)
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
      *(outbuffer + offset + 0) = (this->state_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->state_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->state_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->state_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->state_length);
      for( uint32_t i = 0; i < state_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_statei;
      u_statei.real = this->state[i];
      *(outbuffer + offset + 0) = (u_statei.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->state[i]);
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
      uint32_t state_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      state_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->state_length);
      if(state_lengthT > state_length)
        this->state = (int8_t*)realloc(this->state, state_lengthT * sizeof(int8_t));
      state_length = state_lengthT;
      for( uint32_t i = 0; i < state_length; i++){
      union {
        int8_t real;
        uint8_t base;
      } u_st_state;
      u_st_state.base = 0;
      u_st_state.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->st_state = u_st_state.real;
      offset += sizeof(this->st_state);
        memcpy( &(this->state[i]), &(this->st_state), sizeof(int8_t));
      }
     return offset;
    }

    const char * getType(){ return "cob_phidgets/DigitalSensor"; };
    const char * getMD5(){ return "a7555c23666cea5795a76c1bdec02d2c"; };

  };

}
#endif