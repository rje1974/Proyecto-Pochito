#ifndef _ROS_cob_light_LightMode_h
#define _ROS_cob_light_LightMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/ColorRGBA.h"
#include "cob_light/Sequence.h"

namespace cob_light
{

  class LightMode : public ros::Msg
  {
    public:
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef float _frequency_type;
      _frequency_type frequency;
      typedef float _timeout_type;
      _timeout_type timeout;
      typedef int32_t _pulses_type;
      _pulses_type pulses;
      typedef int8_t _priority_type;
      _priority_type priority;
      uint32_t colors_length;
      typedef std_msgs::ColorRGBA _colors_type;
      _colors_type st_colors;
      _colors_type * colors;
      uint32_t sequences_length;
      typedef cob_light::Sequence _sequences_type;
      _sequences_type st_sequences;
      _sequences_type * sequences;

    LightMode():
      mode(0),
      frequency(0),
      timeout(0),
      pulses(0),
      priority(0),
      colors_length(0), colors(NULL),
      sequences_length(0), sequences(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.real = this->frequency;
      *(outbuffer + offset + 0) = (u_frequency.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_frequency.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_frequency.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_frequency.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->frequency);
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.real = this->timeout;
      *(outbuffer + offset + 0) = (u_timeout.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeout.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeout.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeout.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_pulses;
      u_pulses.real = this->pulses;
      *(outbuffer + offset + 0) = (u_pulses.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_pulses.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_pulses.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_pulses.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->pulses);
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.real = this->priority;
      *(outbuffer + offset + 0) = (u_priority.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->priority);
      *(outbuffer + offset + 0) = (this->colors_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->colors_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->colors_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->colors_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->colors_length);
      for( uint32_t i = 0; i < colors_length; i++){
      offset += this->colors[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->sequences_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sequences_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sequences_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sequences_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->sequences_length);
      for( uint32_t i = 0; i < sequences_length; i++){
      offset += this->sequences[i].serialize(outbuffer + offset);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      union {
        float real;
        uint32_t base;
      } u_frequency;
      u_frequency.base = 0;
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_frequency.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->frequency = u_frequency.real;
      offset += sizeof(this->frequency);
      union {
        float real;
        uint32_t base;
      } u_timeout;
      u_timeout.base = 0;
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeout.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeout = u_timeout.real;
      offset += sizeof(this->timeout);
      union {
        int32_t real;
        uint32_t base;
      } u_pulses;
      u_pulses.base = 0;
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_pulses.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->pulses = u_pulses.real;
      offset += sizeof(this->pulses);
      union {
        int8_t real;
        uint8_t base;
      } u_priority;
      u_priority.base = 0;
      u_priority.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->priority = u_priority.real;
      offset += sizeof(this->priority);
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
      uint32_t sequences_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      sequences_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      sequences_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      sequences_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->sequences_length);
      if(sequences_lengthT > sequences_length)
        this->sequences = (cob_light::Sequence*)realloc(this->sequences, sequences_lengthT * sizeof(cob_light::Sequence));
      sequences_length = sequences_lengthT;
      for( uint32_t i = 0; i < sequences_length; i++){
      offset += this->st_sequences.deserialize(inbuffer + offset);
        memcpy( &(this->sequences[i]), &(this->st_sequences), sizeof(cob_light::Sequence));
      }
     return offset;
    }

    const char * getType(){ return "cob_light/LightMode"; };
    const char * getMD5(){ return "7aecb45b0da2ee8d387f2bec4ee2faf9"; };

  };

}
#endif