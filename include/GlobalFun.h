#pragma once

#include <vector>
#include <string>
#include <list>
#include <ctime>
#include <stdlib.h>
#include <Windows.h>

#  ifdef Dll_LIBRARY                                    // ��Ҫ:����dll�Ĺ�����������Ҫ����ú�;ʹ��dll�Ĺ���,���ܶ���ú�
#    define EXPORT_SINFOTEK   __declspec(dllexport)
#  else
#    define EXPORT_SINFOTEK   __declspec(dllimport)
#  endif

/********************************************************************
* ����ʱ��:        2015-4-01
* ��������:        ȫ�ֺ�����
* ����:            ��ˮ�з���
*
* version��       v1.1.2.0 2015-12-15
* ��ʷ�޸���Ϣ:  
*               6.�汾��v1.1.2 2015-12-22
*                 �޸�ʱ�䣺2015-12-22 18:21
*                 �޸��ߣ��ͺ��
*                 �޸�˵����
*                     �����ļ����ļ��е��ȹز�������

*               5.�汾��v1.1.2 2015-12-15
*                 �޸�ʱ�䣺2015-12-15 15:21
*                 �޸��ߣ��ͺ��
*                 �޸�˵����
*                     ���ӻ�ȡ�ļ�����ָ����׺���ļ����Ƶĺ���findFilesByExtension
*
*               4.�汾��v1.1.1 2015-11-20
*                 �޸�ʱ�䣺2015-11-20 18:44
*                 �޸��ߣ��ͺ��
*                 �޸�˵����
*                     �޸��ַ���ת��ֵ�ຯ����ʹ������Զ�ȥ���ַ���ǰ���ռλ��0
*                     ������std::string extractNumber(const std::string& str)����
*
*               3.�汾��v1.1.0 2015-07-24
*                 �޸�ʱ�䣺2015-07-24 09:21
*                 �޸��ߣ��ͺ��
*                 �޸�˵�����������º���
*                 1��std::wstring stdString2StdWstring(const std::string &str);
*                 2��std::string stdWstring2StdString(const std::wstring &wstr);
*                 3��std::string GetLocalIpAddress();
*
*               2.�汾��v1.0.1 2015-07-03
*                 �޸�ʱ�䣺2015-07-03 15:00
*                 �޸��ߣ��ͺ��
*                 �޸�˵��������std::string int2StdString(int iValue, unsigned int iWidth);
*
*               1.�汾��v1.0.1 2015-04-30
*                 �޸�ʱ�䣺2015-04-30 14:00
*                 �޸��ߣ������
*                 �޸�˵�������ڹ�˾���������ɹ�����ȫ�ֺ����������
*
*********************************************************************/

namespace Sinfotek
{
    // ����ת��
    EXPORT_SINFOTEK int stdString2Int(const std::string &str);                                // stringתΪint
    EXPORT_SINFOTEK bool stdString2Int(const std::string &str, int &iReturn);                 // stringתΪint
    EXPORT_SINFOTEK double stdString2Double(const std::string &str);                          // stringתΪdouble
    EXPORT_SINFOTEK bool stdString2Double(const std::string &str, double &dReturn);           // stringתΪdouble
    EXPORT_SINFOTEK void stdString2StdWstring(const std::string &str, std::wstring &wstr);    // stringתΪwstring
    EXPORT_SINFOTEK std::wstring stdString2StdWstring(const std::string &str);                // stringתΪwstring
    EXPORT_SINFOTEK void stdWstring2StdString(const std::wstring &wstr, std::string &str);    // wstringתΪstring
    EXPORT_SINFOTEK std::string stdWstring2StdString(const std::wstring &wstr);               // wstringתΪstring
    EXPORT_SINFOTEK std::string double2StdString(double dValue, unsigned int precision = 6);  // doubleתΪstring������Чλ
    EXPORT_SINFOTEK std::string int2StdString(int iValue);                                    // intתΪstring  15 -> 15
    EXPORT_SINFOTEK std::string int2StdString(int iValue, unsigned int iWidth);               // intתΪstring  15 -> 0015

    // �ַ�������
    EXPORT_SINFOTEK std::vector<std::string> split(const std::string &strSource, const std::string &divKey);    // �ֽ��ַ���
    EXPORT_SINFOTEK std::string trimString(const std::string &strSource, const std::string &strTrim);           // ɾ���ַ������ض����ַ���
    EXPORT_SINFOTEK std::string extractNumber(const std::string& str);                                          // ��str����ȡ����һ������������,"0739.16Kg/m3"���739.16,"speed:-0.24m/s"���-0.24.
    EXPORT_SINFOTEK std::string eatFrontAndRearSpace(const std::string &strInput);                              // ɾ���ַ�����ǰ����ո� "  kj dk  " ��"kj dk"
    // �ַ�����Сдת��
    EXPORT_SINFOTEK std::string stdString2Upper(const std::string &str);            // stringתΪ��д��string
    EXPORT_SINFOTEK std::string stdString2Lower(const std::string &str);            // stringתΪСд��string

    // ʱ����صĲ���
    EXPORT_SINFOTEK bool time_t2SystemTime(const time_t &time, SYSTEMTIME &sysTime);        // ��ʱ��ת��Ϊϵͳʱ�������
    EXPORT_SINFOTEK time_t systime2Time_t(const SYSTEMTIME &st);                            // ��ϵͳʱ��ת��Ϊtime_t
    EXPORT_SINFOTEK SYSTEMTIME systemTimeAddOrSubtract(const SYSTEMTIME &systemtime, const double& dSecond);     // �Ӽ�������,����Ϊ����
    EXPORT_SINFOTEK std::string systemTime2FileName(const SYSTEMTIME &sysTime);             // ��ϵͳʱ��ת��Ϊ���磺2012-01-03 23-56-45�ĸ�ʽ
    EXPORT_SINFOTEK std::string systemTime2DataString(const SYSTEMTIME &sysTime);           // ��ϵͳʱ��ת��Ϊ���磺2012-01-03 23:56:45.123�ĸ�ʽ
    EXPORT_SINFOTEK std::string time_t2StdString(const time_t &timet);                      // ��ʱ��ת��Ϊ���磺133060998�ĸ�ʽ(ʱ��������)
    EXPORT_SINFOTEK std::string time_t2DataTimeString(const time_t &timet);                 // ��ʱ��ת��Ϊ���磺2012-01-03 23:56:45.123�ĸ�ʽ
    EXPORT_SINFOTEK std::string time_t2FileString(const time_t &timet);                     // ��ʱ��ת��Ϊ���磺2012-01-03 23-56-45�ĸ�ʽ
    EXPORT_SINFOTEK std::string getSystemTimeHMS(std::string str = ":");                    // ��ȡ�����ʽ��ʱ��
    EXPORT_SINFOTEK std::string getSystemDataYMD();                                         // ������磺2013-02-06��ʽ��ʱ���ַ���
    EXPORT_SINFOTEK std::string getSystemDataTime();                                        // ������磺 2013-02-06 15:13:11��ʽ��ʱ���ַ���
    EXPORT_SINFOTEK std::string getSystemTimeShort();                                       // ���ϵͳʱ�� ,���ģʽ

    // bool��ص��ж�
    EXPORT_SINFOTEK bool isAlphaString(const std::string &str);                  // �ж��ַ����Ƿ�ΪӢ���ַ�
    EXPORT_SINFOTEK bool isDigitalString(const std::string &str);                // �ж��Ƿ�ȫ��Ϊ���֣������ж�������С����
    EXPORT_SINFOTEK bool isFileExist(const std::string &strFullPath);            // �ж��ļ��Ƿ����

    // ��ȡ�ļ�·�����ļ���·�����ļ����Ȳ���
    EXPORT_SINFOTEK std::string getFloderPath(const std::string &strFileFullPath);       // ��ȡ�ļ�����·�����βΣ������һ���ļ���·������'/'��'\'
    EXPORT_SINFOTEK std::string getFileNameAndExtension(const std::string &strFullPath); // ��ȡ�ļ�ȫ·��strFullPath��Ӧ�ļ�������׺���ļ���
    EXPORT_SINFOTEK std::string getFileName(const std::string &strFullPath);             // ��ȡ�ļ�ȫ·��strFullPath��Ӧ�ļ���������׺���ļ���
    EXPORT_SINFOTEK std::string getExeFloder(void);                                      // ��ȡ��dll���ڵ��ļ���·��
    EXPORT_SINFOTEK std::string getFileExtension(const std::string &strFilePath);        // ���ļ�·���л�ȡ�ļ��ĺ�׺��

    // �ļ����ļ�����ز���
    EXPORT_SINFOTEK bool createFolder(const std::string &strFolderFullPath);                                                // ���ݲ���·�����𼶴����ļ���
    
    EXPORT_SINFOTEK bool deleteFile(const std::string &strFilePath);                                                        // ɾ���ļ�
    EXPORT_SINFOTEK bool deleteFolder(const std::string &strFolderPath);                                                    // ɾ���ļ��л����ļ�    
    
    EXPORT_SINFOTEK bool copyFile(const std::string &strSourcePath, const std::string &strTargetPath);                      // �����ļ�
    EXPORT_SINFOTEK bool copyFolder(const std::string &strSourceFloderPath, const std::string &strTargetFloderPath);        // �����ļ���
   
    EXPORT_SINFOTEK bool moveFile(const std::string &strSourcePath, const std::string &strTargetPath);                      // �ƶ��ļ�
    EXPORT_SINFOTEK bool moveFloder(const std::string &strSourceFloderPath, const std::string &strTargetFloderPath);                      // �ƶ��ļ�
    
    EXPORT_SINFOTEK bool renameFileByName(const std::string &strSourceFilePath, const std::string &strNewFileName);                         // �ļ�������
    EXPORT_SINFOTEK bool renameFileByNameAndExtention(const std::string &strSourceFilePath, const std::string &strNewFileNameAndExtention); // �ļ�������
    EXPORT_SINFOTEK bool renameFolder(const std::string &strSourceFloderPath, const std::string & strNewFloderName);        // �����ļ���
    
    EXPORT_SINFOTEK std::vector<std::string> findFilesByExtension(std::string strSourceFolder, std::string strExtendName);  // ��ȡָ���ļ�����ָ����׺���ļ��б�
    EXPORT_SINFOTEK bool deleteFilebyExtension(const std::string &folderPath,const std::string &fileExtension);             // ɾ��ָ���ļ�����ĳ���͵��ļ�

    // ��ȡ����IP��ַ
    EXPORT_SINFOTEK std::string GetLocalIpAddress();    
}