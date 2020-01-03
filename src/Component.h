#ifndef COMPONENT_H
#define COMPONENT_H

class Component
{
    public:
	Entity* owner;
	
	virtual ~Component() {}
	virtual void Initializer() {}
	virtual void Update(float) {}
	virtual void Render() {}
}

#endif
