#ifndef _ROS_heatmap_wifi_signal_h
#define _ROS_heatmap_wifi_signal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace heatmap
{

  class wifi_signal : public ros::Msg
  {
    public:
      typedef const char* _essid_type;
      _essid_type essid;
      typedef uint8_t _link_quality_type;
      _link_quality_type link_quality;
      typedef uint8_t _link_quality_max_type;
      _link_quality_max_type link_quality_max;
      typedef int32_t _bitrate_type;
      _bitrate_type bitrate;

    wifi_signal():
      essid(""),
      link_quality(0),
      link_quality_max(0),
      bitrate(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_essid = strlen(this->essid);
      varToArr(outbuffer + offset, length_essid);
      offset += 4;
      memcpy(outbuffer + offset, this->essid, length_essid);
      offset += length_essid;
      *(outbuffer + offset + 0) = (this->link_quality >> (8 * 0)) & 0xFF;
      offset += sizeof(this->link_quality);
      *(outbuffer + offset + 0) = (this->link_quality_max >> (8 * 0)) & 0xFF;
      offset += sizeof(this->link_quality_max);
      union {
        int32_t real;
        uint32_t base;
      } u_bitrate;
      u_bitrate.real = this->bitrate;
      *(outbuffer + offset + 0) = (u_bitrate.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bitrate.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bitrate.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bitrate.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->bitrate);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_essid;
      arrToVar(length_essid, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_essid; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_essid-1]=0;
      this->essid = (char *)(inbuffer + offset-1);
      offset += length_essid;
      this->link_quality =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->link_quality);
      this->link_quality_max =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->link_quality_max);
      union {
        int32_t real;
        uint32_t base;
      } u_bitrate;
      u_bitrate.base = 0;
      u_bitrate.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bitrate.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bitrate.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bitrate.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->bitrate = u_bitrate.real;
      offset += sizeof(this->bitrate);
     return offset;
    }

    const char * getType(){ return "heatmap/wifi_signal"; };
    const char * getMD5(){ return "b1bcb6a0e5568de595abd530de98b7d6"; };

  };

}
#endif