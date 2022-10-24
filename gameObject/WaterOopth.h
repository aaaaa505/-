#pragma once
#include "Object3d.h"
#include "Audio.h"
#include "ParticleManager.h"

//�ő�e��
const int WATEROOPTHBULLET_MAX = 120;

class WaterOopth
{
private: // �G�C���A�X
	using XMFLOAT2 = DirectX::XMFLOAT2;
	using XMFLOAT3 = DirectX::XMFLOAT3;
	using XMFLOAT4 = DirectX::XMFLOAT4;

public: // �ÓI�����o�֐�
	/// <summary>
	/// �C���X�^���X�̐���
	/// </summary>
	/// <returns>�C���X�^���X</returns>
	static WaterOopth* Create();

public: // �����o�֐�

	// �f�X�g���N�^
	~WaterOopth();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(int turnNomber, bool field_completionFlag, bool scene_completionFlag);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// �G�l�~�[��Hp����
	/// </summary>
	void Damage(short player_TypeFlag);

#pragma region setter�Egetter

#pragma region �I�[�v�X
	//���W
	float GetPos() { return bullet.pos[0].z; }

	//�퓬�J�n�t���b�O
	bool GetStartFlag() { return oopth.startFlag; }
	void SetStartflag(bool startFlag) { this->oopth.startFlag = startFlag; }

	//�����蔻��p
	XMFLOAT3 GetCollsionOopth() { return { oopth.pos.x, oopth.pos.y + 0.5f, oopth.pos.z }; }
	float GetSphereRadius() { return oopth.radius; }

	//�G�l�~�[�̗̑�
	int GetHp() { return oopth.hp; }

	//�G�l�~�[�ċN���t���b�O
	bool GetResetFlag() { return oopth.resetFlag; }
	void SetResetFlag(bool resetFlag) { this->oopth.resetFlag = resetFlag; }

	//�U���t���b�O
	bool GetAttackFlag() { return oopth.attackFlag; }

	//�U�������N���t���b�O
	bool GetAttackPreparationFlag() { return oopth.attackPreparationFlag; }
	void SetAttackPreparationFlag(bool attackPreparation) { this->oopth.attackPreparationFlag = attackPreparation; }

	//�U���I���t���b�O
	bool GetAttackEndFlag() { return oopth.attackEndFlag; }

	//��e���̃V�F�C�N���o�N��
	void SetDamegeShakeFlag(bool damegeShakeflag) { this->oopth.damegeShakeFlag = damegeShakeflag; }
#pragma endregion

#pragma region �o���b�g
	//�����蔻��p
	XMFLOAT3 GetCollisionBullet(int i) { return bullet.pos[i]; }

	//�U�����ʃt���b�O
	bool GetHitFlag(int i) { return bullet.hitFlag[i]; }
	void SetHitFlag(bool hitFlag, int i) { this->bullet.hitFlag[i] = hitFlag; }
#pragma endregion


#pragma region �O������
	//���n���V�F�C�N�N���t���b�O
	bool GetShakeFlag() { return shakeFlag; }
	void SetShakeFlag(bool shakeFlag) { this->shakeFlag = shakeFlag; }
#pragma endregion

#pragma endregion
	bool Getdebug() { return bullet.fireFlag[80]; }

private: // �����o�֐�
	/// <summary>
	/// ��������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �퓬�J�n�O����
	/// </summary>
	void Appearance();

	/// <summary>
	/// ���S���o
	/// </summary>
	void Death(int turnNomber);

	/// <summary>
	/// �G�l�~�[���ċN��
	/// </summary>
	void Reset();

	/// <summary>
	/// �I�[�v�X�̃��f���ύX
	/// </summary>
	/// <param name="turnNomber"></param>
	void ModelChange(int turnNomber);

	/// <summary>
	/// �U������
	/// </summary>
	/// <param name="turnNomber"></param>
	void AttackPreparation();

	/// <summary>
	/// ��Ԉڍs
	/// </summary>
	void StatusChange();

	/// <summary>
	/// ���U�p�^�[���P
	/// </summary>
	void BulletLoading_1();

	/// <summary>
	/// ���U�p�^�[���Q
	/// </summary>
	void BulletLoading_2();

	/// <summary>
	/// ���U�p�^�[���R
	/// </summary>
	void BulletLoading_3();

	/// <summary>
	/// �����p�^�[���P
	/// </summary>
	void BulletMove_1(int i);

	/// <summary>
	/// �����p�^�[���Q
	/// </summary>
	void BulletMove_2(int i);

	/// <summary>
	/// �����p�^�[���R
	/// </summary>
	void BulletMove_3(int i);

	/// <summary>
	/// 0�ԁ`39�Ԃ̔��˃t���b�O�����Z�b�g
	/// </summary>
	void FireFlagReset0_39();

	/// <summary>
	/// 40�ԁ`79�Ԃ̔��˃t���b�O�����Z�b�g
	/// </summary>
	void FireFlagReset40_79();

	/// <summary>
	/// 80�ԁ`99�Ԃ̔��˃t���b�O�����Z�b�g
	/// </summary>
	void FireFlagReset80_119();

	/// <summary>
	/// �U���p�^�[��1
	/// </summary>
	void OneSideOrderBlast(bool field_completionFlag);

	/// <summary>
	/// �U���p�^�[��2
	/// </summary>
	/// <param name="completionFlag"></param>
	void TwinSideOrderBlast(bool field_completionFlag);

	/// <summary>
	/// �U���p�^�[��3
	/// </summary>
	/// <param name="field_completionFlag"></param>
	void TwinLineSideBlast(bool field_completionFlag);

	/// <summary>
	/// �I�[�v�X�U�����̃V�F�C�N���o
	/// </summary>
	void AttackShake();

	/// <summary>
	/// �I�[�v�X��e���̃V�F�C�N���o
	/// </summary>
	void DamegeShake();

	/// <summary>
	/// �e�̃p�[�e�B�N�����o
	/// </summary>
	void BulletEffect();

	/// <summary>
	/// �U���I��
	/// </summary>
	void AttackEnd();

private: // �����o�ϐ�

#pragma region ���N���X
	ParticleManager* particleMan = nullptr;
	Audio* audio = nullptr;
#pragma endregion

#pragma region �����g�p���f��
	Model* model_Collision = nullptr;
#pragma endregion

#pragma region �I�[�v�X�\����
	typedef struct Oopth
	{
		//�I�u�W�F�N�g�E���f���E�R���W����
		Object3d* obj = nullptr;
		Model* model_1 = nullptr;
		Model* model_2 = nullptr;
		Model* model_3 = nullptr;
		Object3d* collision = nullptr;

		//�ݒ�ϐ�
		XMFLOAT3 pos{};
		XMFLOAT2 shake{};
		XMFLOAT3 rot{};
		XMFLOAT3 vel{};
		float acc = 0.0f;
		float alpha1 = 0.0f;
		float alpha2 = 0.0f;
		float alpha3 = 0.0f;
		float radius = 0.0f;
		int hp = 0;

		//��ԕω��ϐ�
		bool startFlag = false;
		bool resetFlag = false;
		bool attackPreparationFlag = false;
		bool attackFlag = false;
		bool statusChangeFlag = false;
		int changeTimer = 0;
		float attackShakeTimer = 0.0f;
		bool damegeShakeFlag = false;
		float damegeShakeTimer = 0.0f;
		int attackOrder = 0;
		bool attackEndFlag = false;
		bool fixFlag = false;
		int fixTimer = 0;
	};

	Oopth oopth;
#pragma endregion

#pragma region �T�[�N���\����
	typedef struct Circle
	{
		//�I�u�W�F�N�g�E���f��
		Object3d* obj[6] = { nullptr };
		Model* model = nullptr;

		//�ݒ�ϐ�
		XMFLOAT3 pos[6]{};
		XMFLOAT3 rot{};
		XMFLOAT3 scale{};
	};

	Circle circle;
#pragma endregion

#pragma region �o���b�g�\����
	typedef struct Bullet
	{
		//�I�u�W�F�N�g�E���f��
		Object3d* obj[WATEROOPTHBULLET_MAX] = { nullptr };
		Model* model = nullptr;

		//�ݒ�ϐ�
		XMFLOAT3 pos[WATEROOPTHBULLET_MAX];
		XMFLOAT3 rot[WATEROOPTHBULLET_MAX];

		//��ԕω��ϐ�
		bool hitFlag[WATEROOPTHBULLET_MAX] = { false };
		bool fireFlag[WATEROOPTHBULLET_MAX] = { false };
		int delayTimer = 0;
	};

	Bullet bullet;
#pragma endregion

#pragma region �p�[�e�B�N���\����
	typedef struct Particle
	{
		XMFLOAT3 pos{};
		XMFLOAT3 vel{};
		XMFLOAT3 acc{};
		XMFLOAT4 color{};
	};

	Particle particle;
#pragma endregion

#pragma region �O�����p�ϐ�
	bool shakeFlag = false;
#pragma endregion


};
