//
// Created by Fedor on 04.12.2023.
//

#include "Url.h"

Url::Url(const std::string &url) {
    if (!ParseUrl(url)) {
        href_ = url;
        std::cerr << "Warning: Invalid Url. Many options will not be available.\n";
        is_invalid_ = true;
    }

}

bool Url::ParseUrl(const std::string &url) {
    std::regex rx(
            R"(^((([A-Za-z0-9-]+):)*((([A-Za-z0-9-]+):)\/\/))((((([A-Za-z0-9-]+)(:([A-Za-z0-9-]+))?)@)?(([A-Za-z0-9-]+(\.[A-Za-z0-9-]+)*)(:((6553[0-5])|(655[0-2][0-9])|(65[0-4][0-9]{2})|(6[0-4][0-9]{3})|([1-5][0-9]{4})|([0-5]{0,5})|([0-9]{1,4})))?)))?((((\/[A-Za-z0-9_().-]*)+)?)(\?([A-Za-z0-9._()-]+(=[A-Za-z0-9_()-]+)?)(&[A-Za-z0-9()_-]+(=[A-Za-z0-9_()-]+)?)*)?((#[A-Za-z0-9()&-]+)?)*)*$)",
            std::regex::extended
    );
    std::smatch sm;
    if (!std::regex_match(url, sm, rx)) {
        return false;
    }

    href_ = sm.str(0);
    protocol_ = sm.str(6);
    host_ = sm.str(14);
    hostname_ = sm.str(15);
    port_ = sm.str(18);
    pathname_ = sm.str(28);
    search_ = sm.str(30);
    hash_ = sm.str(36);
    origin_ = sm.str(4) + sm.str(14);
    username_ = sm.str(11);
    password_ = sm.str(13);
    return true;
}

std::string Url::getInfoStr() {
    if (is_invalid_) {
        return "Url is invalid\n";
    }
    std::string out;
    std::string names[] = {"Href", "Protocol", "Host", "Hostname", "Port",
                           "Pathname", "Search", "Hash", "Origin","Username", "Password"};
    std::string values[] = {href_, protocol_, host_, hostname_, port_,
                            pathname_, search_, hash_, origin_, username_,password_};
    const int kSizeVal = 11;
    for (int i = 0; i < kSizeVal; i++) {
        if (!values[i].empty()) {
            out += names[i] + ": " + values[i] + "\n";
        }
    }
    return out;
}

const std::string &Url::getHref() const {
    return href_;
}


const std::string &Url::getProtocol() const {
    return protocol_;
}


const std::string &Url::getHost() const {
    return host_;
}


const std::string &Url::getHostname() const {
    return hostname_;
}


const std::string &Url::getPort() const {
    return port_;
}


const std::string &Url::getPathname() const {
    return pathname_;
}


const std::string &Url::getSearch() const {
    return search_;
}


const std::string &Url::getHash() const {
    return hash_;
}


const std::string &Url::getOrigin() const {
    return origin_;
}


const std::string &Url::getPassword() const {
    return password_;
}


const std::string &Url::getUsername() const {
    return username_;
}


bool Url::isValid() const {
    return !is_invalid_;
}




