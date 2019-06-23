#include "pch.h"

#include "StringEditCStyle.h"



/// Chapter1-1
/// ������AHelloWorld!��HelloJapan?�ɕϊ�����B
/// �{�e�X�g���p�X����R�[�h����������B
/// �ϊ�������HelloWorldToHelloJapan()�Ɏ������邱�ƁBgsgmgms
/// HelloWorldToHelloJapan��I/F�i�����E�߂�j�͓K�X�ύX���Ă悢�B
/// ���L�e�X�g�R�[�h�̎w��͈͓͂K�X�ύX���邱�ƁB
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
TEST(Chapter1, _1_EditStringC) {
	char* helloworld = nullptr;
	{//��������ύX��
		HelloWorldToHelloJapan(helloworld);
	}//�����܂ŕύX��

	EXPECT_EQ(helloworld, "HelloJapan?");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}


/// Chapter1-2
/// ������AHelloWorld!��ByeWorld!�ɕϊ�����B
/// �{�e�X�g���p�X����R�[�h����������B
/// �ϊ�������HelloWorldToByeWorld()�Ɏ������邱�ƁB
/// HelloWorldToByeWorld��I/F�i�����E�߂�j�͓K�X�ύX���Ă悢�B
/// ���L�e�X�g�R�[�h�̎w��͈͓͂K�X�ύX���邱�ƁB
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
TEST(Chapter1, _2_EditStringC) {
	char* helloworld = nullptr;
	{//��������ύX��
		HelloWorldToHelloJapan(helloworld);
	}//�����܂ŕύX��

	EXPECT_EQ(helloworld, "ByeWorld!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}

/// Chapter1-3
/// ������AHelloWorld!��Hello!World!�ɕϊ�����B
/// �{�e�X�g���p�X����R�[�h����������B
/// �ϊ�������HelloWorldToHelloWorld()�Ɏ������邱�ƁB
/// HelloWorldToHelloWorld��I/F�i�����E�߂�j�͓K�X�ύX���Ă悢�B
/// ���L�e�X�g�R�[�h�̎w��͈͓͂K�X�ύX���邱�ƁB
/// Input�̕�����HelloWorld!�ł��邱�Ƃ͑O��Ƃ��Ă悢�B
/// C�͈̔͂Ŏ������邱�ƁBC�W�����C�u�����EWin32API�͎g�p�B
TEST(Chapter1, _3_EditStringC) {
	char* helloworld = nullptr;
	{//��������ύX��
		HelloWorldToHelloJapan(helloworld);
	}//�����܂ŕύX��

	EXPECT_EQ(helloworld, "Hello!World!");
	const char* temp = "HelloWorld!";
	EXPECT_EQ(temp[5], 'W');
}