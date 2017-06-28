#ifndef HTTPCLIENT_H_
#define HTTPCLIENT_H_

#include <curl/curl.h>
#include "json/json.h"
#include "utils.h"

#include "config.h"

struct HttpResponse {
  HttpResponse(const std::string &body_in, unsigned int http_status_code_in, CURLcode curl_code_in,
               const std::string &error_message_in)
      : body(body_in),
        http_status_code(http_status_code_in),
        curl_code(curl_code_in),
        error_message(error_message_in) {}
  std::string body;
  unsigned int http_status_code;
  CURLcode curl_code;
  std::string error_message;
  bool isOk() { return (curl_code == CURLE_OK && http_status_code >= 200 && http_status_code < 203); }
  Json::Value getJson() { return Utils::parseJSON(body); }
};

class HttpClient {
 public:
  HttpClient();
  HttpClient(const HttpClient &);
  virtual ~HttpClient();
  virtual bool authenticate(const AuthConfig &conf);
  virtual bool authenticate(const std::string &cert, const std::string &ca_file, const std::string &pkey);
  virtual HttpResponse get(const std::string &url);
  virtual HttpResponse post(const std::string &url, const Json::Value &data);
  virtual HttpResponse put(const std::string &url, const Json::Value &data);

  virtual bool download(const std::string &url, const std::string &filename);
  bool isAuthenticated() { return authenticated; }
  void setCerts(const std::string &ca, const std::string &cert, const std::string &pkey);
  unsigned int http_code;
  std::string token; /**< the OAuth2 token stored as string */

 private:
  CURL *curl;
  curl_slist *headers;
  HttpResponse perform(CURL *curl_handler, int retry_times);
  bool authenticated;
  std::string user_agent;
  static const int RETRY_TIMES = 2;
};
#endif
