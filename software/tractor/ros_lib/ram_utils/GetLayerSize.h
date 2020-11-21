#ifndef _ROS_SERVICE_GetLayerSize_h
#define _ROS_SERVICE_GetLayerSize_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_utils
{

static const char GETLAYERSIZE[] = "ram_utils/GetLayerSize";

  class GetLayerSizeRequest : public ros::Msg
  {
    public:
      typedef uint32_t _layer_level_type;
      _layer_level_type layer_level;

    GetLayerSizeRequest():
      layer_level(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->layer_level >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->layer_level >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->layer_level >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->layer_level >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layer_level);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->layer_level =  ((uint32_t) (*(inbuffer + offset)));
      this->layer_level |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->layer_level |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->layer_level |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->layer_level);
     return offset;
    }

    const char * getType(){ return GETLAYERSIZE; };
    const char * getMD5(){ return "03d46bb38e79f954b37b030e35978e05"; };

  };

  class GetLayerSizeResponse : public ros::Msg
  {
    public:
      typedef uint32_t _layer_size_type;
      _layer_size_type layer_size;

    GetLayerSizeResponse():
      layer_size(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->layer_size >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->layer_size >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->layer_size >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->layer_size >> (8 * 3)) & 0xFF;
      offset += sizeof(this->layer_size);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->layer_size =  ((uint32_t) (*(inbuffer + offset)));
      this->layer_size |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->layer_size |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->layer_size |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->layer_size);
     return offset;
    }

    const char * getType(){ return GETLAYERSIZE; };
    const char * getMD5(){ return "dc30b75d544b71c1857aa4a33c2f8906"; };

  };

  class GetLayerSize {
    public:
    typedef GetLayerSizeRequest Request;
    typedef GetLayerSizeResponse Response;
  };

}
#endif
