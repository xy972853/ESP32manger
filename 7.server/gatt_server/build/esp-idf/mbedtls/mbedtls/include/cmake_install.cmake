# Install script for directory: H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/gatt_server_demos")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/aes.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/aesni.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/arc4.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/aria.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/asn1.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/asn1write.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/base64.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/bignum.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/blowfish.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/bn_mul.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/camellia.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ccm.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/certs.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/chacha20.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/chachapoly.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/check_config.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/cipher.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/cipher_internal.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/cmac.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/compat-1.3.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/config.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ctr_drbg.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/debug.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/des.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/dhm.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ecdh.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ecdsa.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ecjpake.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ecp.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ecp_internal.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/entropy.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/entropy_poll.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/error.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/gcm.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/havege.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/hkdf.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/hmac_drbg.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/md.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/md2.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/md4.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/md5.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/md_internal.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/memory_buffer_alloc.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/net.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/net_sockets.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/nist_kw.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/oid.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/padlock.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/pem.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/pk.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/pk_internal.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/pkcs11.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/pkcs12.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/pkcs5.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/platform.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/platform_time.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/platform_util.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/poly1305.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ripemd160.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/rsa.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/rsa_internal.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/sha1.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/sha256.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/sha512.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ssl.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ssl_cache.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ssl_ciphersuites.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ssl_cookie.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ssl_internal.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/ssl_ticket.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/threading.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/timing.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/version.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/x509.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/x509_crl.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/x509_crt.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/x509_csr.h"
    "H:/esp-idf-v4.0.1/components/mbedtls/mbedtls/include/mbedtls/xtea.h"
    )
endif()

