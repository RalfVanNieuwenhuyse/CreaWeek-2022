#pragma once
#include "Level.h"
class TestLevel final : public Level
{
public:
	TestLevel();
	virtual void Draw() const override;
	virtual void Update(float elapsedSec) override;
	virtual bool HasReachedEnd() override;
private:

};

