#include "PolymorphicModel.h"

void PolymorphicModel::deleteIfDeletable(const PolymorphicModel* PolymorphicModel) noexcept {
    if(PolymorphicModel->isDeletable()) {
        delete PolymorphicModel;
    }
}

PolymorphicModel::PolymorphicModel(bool deletable) noexcept
: deletable{deletable} { }

bool PolymorphicModel::isDeletable() const noexcept {
    return deletable;
}