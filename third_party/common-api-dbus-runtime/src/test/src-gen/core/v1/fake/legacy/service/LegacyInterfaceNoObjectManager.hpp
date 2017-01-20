/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.1.5.v201512091035.
* Used org.franca.core 0.9.1.201412191134.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_FAKE_LEGACY_SERVICE_LEGACY_INTERFACE_NO_OBJECT_MANAGER_HPP_
#define V1_FAKE_LEGACY_SERVICE_LEGACY_INTERFACE_NO_OBJECT_MANAGER_HPP_



#include <v1/fake/legacy/service/LegacyInterface.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#endif

#include <CommonAPI/Types.hpp>

#undef COMMONAPI_INTERNAL_COMPILATION

namespace v1 {
namespace fake {
namespace legacy {
namespace service {

class LegacyInterfaceNoObjectManager
: virtual public LegacyInterface {
public:
    virtual ~LegacyInterfaceNoObjectManager() { }

    static inline const char* getInterface();
    static inline CommonAPI::Version getInterfaceVersion();
};

const char* LegacyInterfaceNoObjectManager::getInterface() {
    return ("fake.legacy.service.LegacyInterfaceNoObjectManager");
}

CommonAPI::Version LegacyInterfaceNoObjectManager::getInterfaceVersion() {
    return CommonAPI::Version(1, 0);
}


} // namespace service
} // namespace legacy
} // namespace fake
} // namespace v1

namespace CommonAPI {
}


// Compatibility
namespace v1_0 = v1;

#endif // V1_FAKE_LEGACY_SERVICE_LEGACY_INTERFACE_NO_OBJECT_MANAGER_HPP_