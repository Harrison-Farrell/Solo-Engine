// -----------------------------------------------------------------------------
// Author:      Harrison Farrell
// Project:     Solo-Engine Simulation Engine
// Copyright:   (c) 2026 Harrison Farrell. All Rights Reserved.
//
// Licensed under the GNU Affero General Public License v3.0 (AGPL-3.0).
// This program is distributed WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
// See <https://www.gnu.org/licenses/agpl-3.0.html> for full details.
// -----------------------------------------------------------------------------

#ifndef SOLO_AIS_MESSAGES_BASE_MESSAGE_H
#define SOLO_AIS_MESSAGES_BASE_MESSAGE_H

#include <string>

namespace solo {
namespace ais {
namespace messages {

class BaseMessage {
public:
    BaseMessage() = default;
    virtual ~BaseMessage();

    // Prevent copy and assignment
    BaseMessage(const BaseMessage&) = delete;
    BaseMessage& operator=(const BaseMessage&) = delete;

    // Prevent move and assignment
    BaseMessage(BaseMessage&&) = delete;
    BaseMessage& operator=(BaseMessage&&) = delete;

    virtual void Print() const = 0;
    virtual std::string Encode() const = 0;
    virtual void Decode(const std::string& payload) = 0;
};

}  // namespace messages
}  // namespace ais
}  // namespace solo

#endif  // SOLO_AIS_MESSAGES_BASE_MESSAGE_H
