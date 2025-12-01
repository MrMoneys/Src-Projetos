#ifndef IPBLOCKER_H
#define IPBLOCKER_H

#include <string>
#include <unordered_set>


class IPBlocker {
public:
    IPBlocker() {
        // Apne blocked servers/dns yaha daalo
        blocked.insert("ff-sdk-grtc.freefireind.in");
        blocked.insert("freefireind.in");
        blocked.insert("http://103.16.33.161");  // Prefix match
    }

    bool isBlocked(const std::string& ipOrDomain) const {
        for (const auto& b : blocked) {
            if (ipOrDomain.rfind(b, 0) == 0) { // agar prefix/domain match hua
                return true;
            }
        }
        return false;
    }

private:
    std::unordered_set<std::string> blocked;

    void initializeBlockedIPs() {
        // Blocked IPs and prefixes
        const std::string blockedIPsList[] = {
            "192.168.1.1", "192.168.31.1", "192.168.0.1", "10.0.0.1",
            "1.1.1.1", "8.8.8.8", "8.8.4.4", "114.114.114.114",
            "203.116.180.99", "202.81.117.88", "202.81.118.4",
            "49.51.133.79", "164.52.102.", "103.16.33.", "127.0.0.0",
            "199.", "164.", "60.", "63.", "56.", "103.219.201.",
            "49.51.42.152", "49.51.185.106", "150.109.185.81",
            "ff-sdk-grtc.freefireind.in", "103.16.33.161", "103.16.33.171"
            // Add more IPs/prefixes as needed
        };

        for (const auto& ip : blockedIPsList) {
            blocked.insert(ip);
        }
    }
};

#endif // IPBLOCKER_H
