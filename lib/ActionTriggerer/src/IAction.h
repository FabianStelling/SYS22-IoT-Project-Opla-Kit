//
// Created by HP on 07.06.2024.
//

#ifndef IACTION_H
#define IACTION_H

class IAction {
public:
    virtual ~IAction() = default;
    virtual void doAction() = 0;
};

#endif // IACTION_H
