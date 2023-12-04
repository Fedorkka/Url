#include "gtest/gtest.h"
#include "Url.h"


TEST(UrlTestSuite, FullPiecesUrl) {
    Url exUrl("scheme://username:password@subdomain.domain.tld:443/path/file-name.suffix?query-string#hash");
    ASSERT_EQ(exUrl.isValid(), true);
    ASSERT_EQ(exUrl.getHref(),
              "scheme://username:password@subdomain.domain.tld:443/path/file-name.suffix?query-string#hash");
    ASSERT_EQ(exUrl.getProtocol(), "scheme");
    ASSERT_EQ(exUrl.getHost(), "subdomain.domain.tld:443");
    ASSERT_EQ(exUrl.getHostname(), "subdomain.domain.tld");
    ASSERT_EQ(exUrl.getPort(), "443");
    ASSERT_EQ(exUrl.getPathname(), "/path/file-name.suffix");
    ASSERT_EQ(exUrl.getSearch(), "?query-string");
    ASSERT_EQ(exUrl.getHash(), "#hash");
    ASSERT_EQ(exUrl.getOrigin(), "scheme://subdomain.domain.tld:443");
    ASSERT_EQ(exUrl.getUsername(), "username");
    ASSERT_EQ(exUrl.getPassword(), "password");

}

TEST(UrlTestSuite, FtpRandomUrl) {
    Url exUrl("ftp://198.133.219.25:21");
    ASSERT_EQ(exUrl.isValid(), true);
    ASSERT_EQ(exUrl.getHref(), "ftp://198.133.219.25:21");
    ASSERT_EQ(exUrl.getProtocol(), "ftp");
    ASSERT_EQ(exUrl.getHost(), "198.133.219.25:21");
    ASSERT_EQ(exUrl.getHostname(), "198.133.219.25");
    ASSERT_EQ(exUrl.getPort(), "21");
    ASSERT_EQ(exUrl.getPathname(), "");
    ASSERT_EQ(exUrl.getSearch(), "");
    ASSERT_EQ(exUrl.getHash(), "");
    ASSERT_EQ(exUrl.getOrigin(), "ftp://198.133.219.25:21");
    ASSERT_EQ(exUrl.getUsername(), "");
    ASSERT_EQ(exUrl.getPassword(), "");
}

TEST(UrlTestSuite, HttpsRandomUrl) {
    Url exUrl("https://www.sample.edu/?dock=support&umbrella=amusement#can");
    ASSERT_EQ(exUrl.isValid(), true);
    ASSERT_EQ(exUrl.getHref(), "https://www.sample.edu/?dock=support&umbrella=amusement#can");
    ASSERT_EQ(exUrl.getProtocol(), "https");
    ASSERT_EQ(exUrl.getHost(), "www.sample.edu");
    ASSERT_EQ(exUrl.getHostname(), "www.sample.edu");
    ASSERT_EQ(exUrl.getPort(), "");
    ASSERT_EQ(exUrl.getPathname(), "/");
    ASSERT_EQ(exUrl.getSearch(), "?dock=support&umbrella=amusement");
    ASSERT_EQ(exUrl.getHash(), "#can");
    ASSERT_EQ(exUrl.getOrigin(), "https://www.sample.edu");
    ASSERT_EQ(exUrl.getUsername(), "");
    ASSERT_EQ(exUrl.getPassword(), "");
}
