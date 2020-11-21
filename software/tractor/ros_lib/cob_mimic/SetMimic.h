#ifndef _ROS_SERVICE_SetMimic_h
#define _ROS_SERVICE_SetMimic_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_mimic
{

static const char SETMIMIC[] = "cob_mimic/SetMimic";

  class SetMimicRequest : public ros::Msg
  {
    public:
      typedef const char* _mimic_type;
      _mimic_type mimic;
      typedef float _speed_type;
      _speed_type speed;
      typedef int64_t _repeat_type;
      _repeat_type repeat;

    SetMimicRequest():
      mimic(""),
      speed(0),
      repeat(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_mimic = strlen(this->mimic);
      varToArr(outbuffer + offset, length_mimic);
      offset += 4;
      memcpy(outbuffer + offset, this->mimic, length_mimic);
      offset += length_mimic;
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.real = this->speed;
      *(outbuffer + offset + 0) = (u_speed.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_speed.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_speed.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_speed.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->speed);
      union {
        int64_t real;
        uint64_t base;
      } u_repeat;
      u_repeat.real = this->repeat;
      *(outbuffer + offset + 0) = (u_repeat.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_repeat.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_repeat.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_repeat.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_repeat.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_repeat.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_repeat.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_repeat.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->repeat);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_mimic;
      arrToVar(length_mimic, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_mimic; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_mimic-1]=0;
      this->mimic = (char *)(inbuffer + offset-1);
      offset += length_mimic;
      union {
        float real;
        uint32_t base;
      } u_speed;
      u_speed.base = 0;
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_speed.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->speed = u_speed.real;
      offset += sizeof(this->speed);
      union {
        int64_t real;
        uint64_t base;
      } u_repeat;
      u_repeat.base = 0;
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_repeat.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->repeat = u_repeat.real;
      offset += sizeof(this->repeat);
     return offset;
    }

    const char * getType(){ return SETMIMIC; };
    const char * getMD5(){ return "6046fb0fc821e346cac6470d0911e088"; };

  };

  class SetMimicResponse : public ros::Msg
  {
    public:
      typedef bool _success_type;
      _success_type success;
      typedef const char* _message_type;
      _message_type message;

    SetMimicResponse():
      success(0),
      message("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      uint32_t length_message = strlen(this->message);
      varToArr(outbuffer + offset, length_message);
      offset += 4;
      memcpy(outbuffer + offset, this->message, length_message);
      offset += length_message;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
      uint32_t length_message;
      arrToVar(length_message, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_message; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_message-1]=0;
      this->message = (char *)(inbuffer + offset-1);
      offset += length_message;
     return offset;
    }

    const char * getType(){ return SETMIMIC; };
    const char * getMD5(){ return "937c9679a518e3a18d831e57125ea522"; };

  };

  class SetMimic {
    public:
    typedef SetMimicRequest Request;
    typedef SetMimicResponse Response;
  };

}
#endif
