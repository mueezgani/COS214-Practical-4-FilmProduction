#ifndef WORKGROUP_H
#define WORKGROUP_H

#include <string>
#include <vector>

#include "WorkItem.h"

class WorkGroup : public WorkItem
{
protected:
    std::string name;
    std::vector<WorkItem*> children;

public:
    WorkGroup(const std::string& name);
    virtual ~WorkGroup();

    void add(WorkItem* item);
    void remove(WorkItem* item);
    WorkItem* getChild(int index) const;

    void process() override;
    std::string getName() const override;
    Priority getPriority() const override;
};

#endif