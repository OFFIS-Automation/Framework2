// OFFIS Automation Framework
// Copyright (C) 2013-2016 OFFIS e.V.
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef BOOLEANPORT_H
#define BOOLEANPORT_H

#include <ports/OverlayPort.h>
#include "FilterPortsGlobal.h"

namespace port
{
    class FILTER_PORTS_SHARED_EXPORT Boolean : public OverlayPort
    {
    protected:
        Boolean();
        QString toString(const QVariant &var) const;
        QVariant fromString(const QString &str) const;
        QVariant constrainedValue(const QVariant &var) const { return var; }
    };
}

namespace out
{
    class FILTER_PORTS_SHARED_EXPORT Boolean : public port::Boolean
    {
    public:
        void send(bool value);
    };
};

namespace in
{
    class FILTER_PORTS_SHARED_EXPORT Boolean : public port::Boolean
    {
    public:
        bool getValue();
        inline operator bool() { return getValue(); }
        void setDefault(bool value);
    };
}

#endif // BOOLEANPORT_H