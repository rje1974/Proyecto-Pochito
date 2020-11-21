#ifndef _ROS_SERVICE_GetNumberOfLayersLevels_h
#define _ROS_SERVICE_GetNumberOfLayersLevels_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ram_utils
{

static const char GETNUMBEROFLAYERSLEVELS[] = "ram_utils/GetNumberOfLayersLevels";

  class GetNumberOfLayersLevelsRequest : public ros::Msg
  {
    public:

    GetNumberOfLayersLevelsRequest()
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

    const char * getType(){ return GETNUMBEROFLAYERSLEVELS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class GetNumberOfLayersLevelsResponse : public ros::Msg
  {
    public:
      typedef uint32_t _number_of_layers_type;
      _number_of_layers_type number_of_layers;

    GetNumberOfLayersLevelsResponse():
      number_of_layers(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->number_of_layers >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->number_of_layers >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->number_of_layers >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->number_of_layers >> (8 * 3)) & 0xFF;
      offset += sizeof(this->number_of_layers);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->number_of_layers =  ((uint32_t) (*(inbuffer + offset)));
      this->number_of_layers |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->number_of_layers |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->number_of_layers |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->number_of_layers);
     return offset;
    }

    const char * getType(){ return GETNUMBEROFLAYERSLEVELS; };
    const char * getMD5(){ return "032958e91a43e187a4a727f9fbdd23bc"; };

  };

  class GetNumberOfLayersLevels {
    public:
    typedef GetNumberOfLayersLevelsRequest Request;
    typedef GetNumberOfLayersLevelsResponse Response;
  };

}
#endif
