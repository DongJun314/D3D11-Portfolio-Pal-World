#pragma once
#include "TaskNode.h"

namespace Engine
{
	class CMeshComponent;
}

namespace Client
{
	class CMonster;

	/********************
		Description
	********************/
	struct FTaskPengulletCannonDesc : public FTaskNodeDesc
	{
		int32 m_iAnimationID = -1;
	};

	class CTaskPengulletCannon final : public CTaskNode
	{
	/********************
		Ctor/Dtor
	********************/
	public:
		explicit CTaskPengulletCannon() = default;

		virtual ~CTaskPengulletCannon() = default;

	/********************
		Events
	********************/
	public:
		static std::shared_ptr<CTaskPengulletCannon> Create(const std::shared_ptr<FTaskPengulletCannonDesc>& _spTaskPengulletCannonDesc);

		virtual HRESULT Initialize(const shared_ptr<FBTNodeDesc>& _spNodeDesc) override;

	public:
		virtual void OnNodeInit(float _fDeltaSecond) override;

		virtual void OnNodeEnter(float _fDeltaSecond) override;

		virtual EBTNodeResult ExecuteTaskNode(float _fDeltaSecond) override;

		virtual void Release() override;

	/********************
		Data Members
	********************/
	private:
		std::shared_ptr<CMeshComponent> m_spMeshComponent = nullptr;

		std::shared_ptr<CMonster> m_spMonster = nullptr;
	
	private:
		float m_fSumDurationDeltaSeconds = 0.0f;

		const float m_fMaxDurationDeltaSeconds = 30.0f;

		int32 m_iAnimationID = -1;
	};
}
