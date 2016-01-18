/**
 * @file helpers.h
 * @brief header file for restclient-cpp helpers
 * @author Daniel Schauenberg <d@unwiredcouch.com>
 * @version
 * @date 2010-10-11
 */

#ifndef INCLUDE_RESTCLIENT_CPP_HELPERS_H_
#define INCLUDE_RESTCLIENT_CPP_HELPERS_H_

#include <string>
#include <algorithm>
#include <functional>

#include "restclient-cpp/version.h"

/**
 * @brief namespace for all RestClient definitions
 */
namespace RestClient {

/**
  * @brief: namespace for all helper functions
  */
namespace Helpers {

  /** @struct upload_object
    *  @brief This structure represents the payload to upload on POST
    *  requests
    *  @var upload_object::data
    *  Member 'data' contains the data to upload
    *  @var upload_object::length
    *  Member 'length' contains the length of the data to upload
    */
  typedef struct {
    const char* data;
    size_t length;
  } UploadObject;

  // writedata callback function
  static size_t write_callback(void *ptr, size_t size, size_t nmemb,
                              void *userdata);

  // header callback function
  static size_t header_callback(void *ptr, size_t size, size_t nmemb,
                                void *userdata);
  // read callback function
  static size_t read_callback(void *ptr, size_t size, size_t nmemb,
                              void *userdata);

  // trim from start
  static inline std::string &ltrim(const std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
          std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
  }

  // trim from end
  static inline std::string &rtrim(const std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
          std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
  }

  // trim from both ends
  static inline std::string &trim(const std::string &s) {
    return ltrim(rtrim(s));
  }
};  // namespace Helpers

};  // namespace RestClient

#endif  // INCLUDE_RESTCLIENT_CPP_HELPERS_H_
