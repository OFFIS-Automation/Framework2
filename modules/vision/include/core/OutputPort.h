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

#ifndef OUTPUTPORT_H
#define OUTPUTPORT_H

#include <filter/FilterGlobal.h>

#include <QSet>
#include <QMutex>
#include <QElapsedTimer>
#include <QVariant>
#include <core/PortInfo.h>

class PortListener;
class Port;

class FILTER_SHARED_EXPORT OutputPort
{
public:
    OutputPort(Port& parent);
    virtual void send(const QVariant& val);
    virtual void finish(){}
    PortInfo getInfo();
    QString name() const;
    void addTarget(PortListener* inputPort);
    void removeTarget(PortListener* inputPort);
    bool hasFired() const { return mFired; }
    void resetFired() { mFired = false; }
    QVariant lastValue();
    bool isNormalType() const;

protected:
    OutputPort(Port& parent, bool isArray);
    Port& mParent;
    QMutex mMutex, mLastValueMutex;
    bool mFired;
    QVariant mLastValue;
    QSet<PortListener*> mTargets;
    QString mFilterName;
    int mTraceId;
};

class OutputListPort : public OutputPort
{
public:
    OutputListPort(Port& parent);
    void send(const QVariant& var);
    void finish();
protected:
    QList<QVariant> mValueList;
};

#endif // OUTPUTPORT_H