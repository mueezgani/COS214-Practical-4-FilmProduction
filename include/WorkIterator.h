#ifndef WORKITERATOR_H
#define WORKITERATOR_H

class WorkItem;

class WorkIterator
{
public:
    virtual ~WorkIterator() {}

    virtual bool hasNext() const = 0;
    virtual WorkItem* next() = 0;
    virtual void reset() = 0;
};

#endif