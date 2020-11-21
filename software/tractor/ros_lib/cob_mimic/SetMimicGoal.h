#ifndef _ROS_cob_mimic_SetMimicGoal_h
#define _ROS_cob_mimic_SetMimicGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_mimic
{

  class SetMimicGoal : public ros::Msg
  {
    public:
      typedef const char* _mimic_type;
      _mimic_type mimic;
      typedef float _speed_type;
      _speed_type speed;
      typedef int64_t _repeat_type;
      _repeat_type repeat;

    SetMimicGoal():
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

    const char * getType(){ return "cob_mimic/SetMimicGoal"; };
    const char * getMD5(){ return "6046fb0fc821e346cac6470d0911e088"; };

  };

}
#endif