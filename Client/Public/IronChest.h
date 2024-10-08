#pragma once
#include "Architecture.h"

namespace Engine
{
	class CPanel;
}

namespace Client
{
	struct FIronChestDesc : public FArchitectureDesc
	{
	};

	class CIronChest final : public CArchitecture
	{
	/********************
		Ctor/Dtor
	********************/
	public:
		explicit CIronChest() = default;

		virtual ~CIronChest() = default;

	/********************
		Events
	********************/
	public:
		static std::shared_ptr<CIronChest> Create(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc);

		virtual HRESULT Initialize(const std::shared_ptr<FGameObjectDesc>& _spGameObjectDesc) override;

		virtual HRESULT BeginPlay() override;

		virtual int32 PreTick(float _fDeltaSeconds) override;

		virtual int32 Tick(float _fDeltaSeconds) override;

		virtual int32 PostTick(float _fDeltaSeconds) override;

		virtual HRESULT EndPlay() override;

		virtual void Release() override;
		
	/********************
		Methods
	********************/
	public:
		virtual void RecycleFromPool() { return; }

		virtual void ReturnToPool() { return; }

	private:
		virtual HRESULT InitializeMeshComponent() override;

		virtual HRESULT InitializeColliderComponent() override;

	public:
		void AddItemToIronChest(EItemType _eItemType, int32 _iNumItems);

	/********************
		Data Members
	********************/
	private:
		/* == F를 누르지 않았을 때 == */
		// 패널 : 버튼 선택
		// [F] : 열기
		// [V] : 보안 설정
		// [C] : 상자 설정
		// [4] : 수리
		std::shared_ptr<CPanel> m_spSelectPanel = nullptr;
		
		/* == F를 눌렀을 때 == */
		// 패널 : 인벤토리 -> 아마 인벤 시스템에서 가져와서 띄울 것으로 보여서 제외
		// std::shared_ptr<CPanel> m_spInventoryWindow = nullptr;
		// 패널 : 상자 아이템 목록
		std::shared_ptr<CPanel> m_spChestWindow = nullptr;

	private:
		std::weak_ptr<CChestBoxSystem> m_wpChestBoxSystem;
	};
}
