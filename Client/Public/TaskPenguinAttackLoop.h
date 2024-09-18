#pragma once
#include "TaskNode.h"

namespace Engine
{
	class CMeshComponent;
}

namespace Client
{
	class CCreature;
	class CMonster;
	class CEffectManager;
	class CProjectileEffectGroup;

	/********************
		Description
	********************/
	struct FTaskPenguinAttackLoopDesc : public FBTNodeDesc
	{
		std::wstring m_wstrProjectileEffectName = L"";

		ECollisionLayer m_eProjectileCollisionLayer = ECollisionLayer::ENUM_END;

		ECollisionFlag m_eProjectileCollsionFlag = ECollisionFlag::ENUM_END;

		std::shared_ptr<CCreature> m_spTarget = nullptr;

		int32 m_iActionAnimationID = -1;

		int32 m_iActionLoopAnimationID = -1;
	};

	class CTaskPenguinAttackLoop final : public CTaskNode
	{
	/********************
		Ctor/Dtor
	********************/
	public:
		explicit CTaskPenguinAttackLoop() = default;

		virtual ~CTaskPenguinAttackLoop() = default;

	/********************
		Events
	********************/
	public:
		static std::shared_ptr<CTaskPenguinAttackLoop> Create(const std::shared_ptr<FTaskPenguinAttackLoopDesc>& _spTaskAttackLoopDesc);

		virtual HRESULT Initialize(const shared_ptr<FBTNodeDesc>& _spNodeDesc) override;

	public:
		virtual void OnNodeInit(float _fDeltaSecond) override;

		virtual void OnNodeEnter(float _fDeltaSecond) override;

		virtual EBTNodeResult ExecuteTaskNode(float _fDeltaSecond) override;

		virtual void Release() override;
	/********************
		Methods
	********************/
	private:
		void InitializeProjectileEffectGroups(const std::wstring& _wstrProjectileEffectGroupName, ECollisionLayer _eCollisionLayer, ECollisionFlag _eCollisionFlag);
		
		HRESULT ActivateProjectileEffectGroup(int32 _iProjectileSlot, std::shared_ptr<CCreature> _spTarget, const Vector3 _vActivatedPosition);

	/********************
		Data Members
	********************/
	private:
		std::shared_ptr<CMonster> m_spMonster = nullptr;
		
		std::weak_ptr<CCreature> m_wpTarget;

		std::shared_ptr<CMeshComponent> m_spMeshComponent = nullptr;

		std::weak_ptr<CEffectManager> m_wpEffectManager;

	private:
		int32 m_iActionAnimationID = -1;

		int32 m_iActionLoopAnimationID = -1;

		bool m_bActionCompleted = false;

		float m_fSumAttackDeltaSeconds = 0.0f;

		const float m_fMaxAttackDeltaSeconds = 3.0f;

		int32 m_iMissileCount = 0;

	private:
		std::unordered_map<int32, std::vector<std::shared_ptr<CProjectileEffectGroup>>> m_umapProjectileEffectGroups;
	};
}
