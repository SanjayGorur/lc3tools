/*
 * Copyright 2020 McGraw-Hill Education. All rights reserved. No reproduction or distribution without the prior written consent of McGraw-Hill Education.
 */
#ifndef SIM_NEW_H
#define SIM_NEW_H

#include <cstdint>
#include <queue>

#include "events_new.h"
#include "state_new.h"

namespace std
{
    using namespace lc3::core;

    template<> struct greater<PIEvent>
    {
        bool operator()(PIEvent lhs, PIEvent rhs)
        {
            return std::greater<uint64_t>()(lhs->time_delta, rhs->time_delta);
        }
    };
};

namespace lc3
{
namespace core
{
    class SimulatorNew
    {
    private:
        std::priority_queue<PIEvent, std::vector<PIEvent>, std::greater<PIEvent>> events;
        MachineState state;
        uint64_t time;

    public:
        SimulatorNew(void);
        void main(void);
    };
};
};

#endif
