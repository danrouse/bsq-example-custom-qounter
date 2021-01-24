#pragma once

#include "custom-types/shared/macros.hpp"
#include "qounters-minus/shared/Qounter.hpp"
#include "qounters-minus/shared/QounterRegistry.hpp"

DECLARE_CLASS_CODEGEN(ExampleCustomQounter, Qounter, QountersMinus::Qounter,
    DECLARE_STATIC_FIELD(bool, Enabled);
    DECLARE_STATIC_FIELD(int, Position);
    DECLARE_STATIC_FIELD(int, Distance);

    DECLARE_METHOD(static void, Register);
    DECLARE_METHOD(void, Start);
    DECLARE_METHOD(void, OnNoteCut, Il2CppObject* data, Il2CppObject* info);

    REGISTER_FUNCTION(Qounter,
        REGISTER_FIELD(Enabled);
        REGISTER_FIELD(Position);
        REGISTER_FIELD(Distance);

        REGISTER_METHOD(Register);
        REGISTER_METHOD(Start);
        REGISTER_METHOD(OnNoteCut);
    )
)
