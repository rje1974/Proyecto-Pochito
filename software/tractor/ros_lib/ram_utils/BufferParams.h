#ifndef _ROS_SERVICE_BufferParams_h
#define _ROS_SERVICE_BufferParams_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_utils
{

static const char BUFFERPARAMS[] = "ram_utils/BufferParams";

  class BufferParamsRequest : public ros::Msg
  {
    public:
      typedef uint32_t _button_id_type;
      _button_id_type button_id;

    BufferParamsRequest():
      button_id(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->button_id >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->button_id >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->button_id >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->button_id >> (8 * 3)) & 0xFF;
      offset += sizeof(this->button_id);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->button_id =  ((uint32_t) (*(inbuffer + offset)));
      this->button_id |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->button_id |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->button_id |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->button_id);
     return offset;
    }

    const char * getType(){ return BUFFERPARAMS; };
    const char * getMD5(){ return "3ac924e2e4db3d63b125ca3c77265a9f"; };

  };

  class BufferParamsResponse : public ros::Msg
  {
    public:
      typedef const char* _error_type;
      _error_type error;

    BufferParamsResponse():
      error("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_error = strlen(this->error);
      varToArr(outbuffer + offset, length_error);
      offset += 4;
      memcpy(outbuffer + offset, this->error, length_error);
      offset += length_error;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_error;
      arrToVar(length_error, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_error; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_error-1]=0;
      this->error = (char *)(inbuffer + offset-1);
      offset += length_error;
     return offset;
    }

    const char * getType(){ return BUFFERPARAMS; };
    const char * getMD5(){ return "eca8b96616c32aacf1be8bbf14c70eba"; };

  };

  class BufferParams {
    public:
    typedef BufferParamsRequest Request;
    typedef BufferParamsResponse Response;
  };

}
#endif
