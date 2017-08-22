#include "Model.h"

void Model::deleteIfDeletable(const Model* model) noexcept {
    if(model->isDeletable()) {
        delete model;
    }
}

Model::Model(bool deletable) noexcept
: deletable{deletable} { }

bool Model::isDeletable() const noexcept {
    return deletable;
}