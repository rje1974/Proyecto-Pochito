#ifndef _ROS_cob_sound_SayGoal_h
#define _ROS_cob_sound_SayGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_sound
{

  class SayGoal : public ros::Msg
  {
    public:
      typedef const char* _text_type;
      _text_type text;

    SayGoal():
      text("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_text = strlen(this->text);
      varToArr(outbuffer + offset, length_text);
      offset += 4;
      memcpy(outbuffer + offset, this->text, length_text);
      offset += length_text;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_text;
      arrToVar(length_text, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_text; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_text-1]=0;
      this->text = (char *)(inbuffer + offset-1);
      offset += length_text;
     return offset;
    }

    const char * getType(){ return "cob_sound/SayGoal"; };
    const char * getMD5(){ return "74697ed3d931f6eede8bf3a8dfeca160"; };

  };

}
#endif