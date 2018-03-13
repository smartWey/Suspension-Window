# Host: 127.0.0.1  (Version 5.7.12-log)
# Date: 2018-02-27 16:41:31
# Generator: MySQL-Front 5.4  (Build 1.1)

/*!40101 SET NAMES utf8 */;

#
# Structure for table "qinghua_flow"
#

DROP TABLE IF EXISTS `qinghua_flow`;
CREATE TABLE `qinghua_flow` (
  `id` int(3) NOT NULL,
  `TwentyFive` int(4) DEFAULT NULL,
  `TwentyEight` int(4) DEFAULT NULL,
  `TwentyEleven` int(4) DEFAULT NULL,
  `TwentyForteen` int(4) DEFAULT NULL,
  `TwentySeventeen` int(4) DEFAULT NULL,
  `TwentyTwenty` int(4) DEFAULT NULL,
  `TwentyTwentyThree` int(4) DEFAULT NULL,
  `TwentyOneTwo` int(4) DEFAULT NULL,
  `TwentyOneFive` int(4) DEFAULT NULL,
  `TwentyOneEight` int(4) DEFAULT NULL,
  `TwentyOneEleven` int(4) DEFAULT NULL,
  `TwentyOneForteen` int(4) DEFAULT NULL,
  `TwentyOneSeventeen` int(4) DEFAULT NULL,
  `TwentyOneTwenty` int(4) DEFAULT NULL,
  `TwentyOneTwentyThree` int(4) DEFAULT NULL,
  `TwentyTwoTwo` int(4) DEFAULT NULL,
  `TwentyTwoFive` int(4) DEFAULT NULL,
  `TwentyTwoEight` int(4) DEFAULT NULL,
  `TwentyTwoEleven` int(4) DEFAULT NULL,
  `TwentyTwoForteen` int(4) DEFAULT NULL,
  `TwentyTwoSeventeen` int(4) DEFAULT NULL,
  `TwentyTwoTwenty` int(4) DEFAULT NULL,
  `TwentyTwoTwentyThree` int(4) DEFAULT NULL,
  `TwentyThreeTwo` int(4) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Data for table "qinghua_flow"
#

INSERT INTO `qinghua_flow` VALUES (0,6,6,5,5,4,4,3,4,4,7,110,1540,537,240,145,100,60,45,40,35,30,24,18,14),(5,12,12,10,10,8,8,6,8,8,14,76,536,174,167,101,69,41,31,85,74,63,51,38,29),(10,18,18,15,15,12,12,9,12,12,21,108,1220,529,236,142,98,59,44,124,108,93,74,55,43),(20,24,24,20,20,16,16,12,16,16,28,131,2130,643,287,173,119,71,53,163,142,122,97,73,57),(50,31,31,26,26,21,21,15,21,21,36,154,3570,755,337,204,140,84,63,210,184,158,126,94,73),(100,37,37,31,31,24,24,18,24,24,43,167,4770,815,364,220,151,91,68,248,217,186,148,111,86),(300,45,45,38,38,30,30,22,30,30,53,181,6850,888,396,239,165,99,74,306,268,229,183,137,107);

#
# Structure for table "qinghua_input"
#

DROP TABLE IF EXISTS `qinghua_input`;
CREATE TABLE `qinghua_input` (
  `id` int(2) NOT NULL AUTO_INCREMENT,
  `name` varchar(254) DEFAULT NULL COMMENT '建筑物名称',
  `levelBuild` int(4) DEFAULT NULL COMMENT '工程等级',
  `standerdFlood` int(4) DEFAULT NULL COMMENT '设计洪水标准',
  `strengthConcrete` int(4) DEFAULT NULL COMMENT '槽深混凝土强度',
  `spanBuild` int(4) DEFAULT NULL COMMENT '建筑物跨度',
  `waterFlow` int(4) DEFAULT NULL COMMENT '设计输水流量',
  `measuresImpervious` int(4) DEFAULT NULL COMMENT '防渗措施',
  `qualityDefect` int(4) DEFAULT NULL COMMENT '检查质量缺陷',
  `reinforceMethod` int(4) DEFAULT NULL COMMENT '加固方法',
  `newTect` int(4) DEFAULT NULL COMMENT '新技术的采用',
  `estimateAbility` int(1) DEFAULT NULL COMMENT '是否预应力',
  `earthquakeIntensity` int(1) DEFAULT NULL COMMENT '地震烈度',
  `excellent` double(5,2) DEFAULT NULL COMMENT '验收优良率',
  `levelImpervious` int(4) DEFAULT NULL COMMENT '防渗等级',
  `levelAntifreeze` int(4) DEFAULT NULL COMMENT '抗冻等级',
  `staticRisk` double(3,2) DEFAULT NULL COMMENT '静态风险度',
  `probabilityFlood` double(4,2) DEFAULT NULL COMMENT '超标准洪水概率',
  `flow` double(6,2) DEFAULT NULL COMMENT '流量',
  `sandExtraction` int(4) DEFAULT NULL COMMENT '采砂影响',
  `localDestroy` int(4) DEFAULT NULL COMMENT '局部破坏',
  `freezeCracking` int(4) DEFAULT NULL COMMENT '冻融开裂',
  `dynamicRisk` double(6,2) DEFAULT NULL COMMENT '动态风险度',
  `buildRisk` double(6,2) DEFAULT NULL COMMENT '结构运行风险',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8;

#
# Data for table "qinghua_input"
#

INSERT INTO `qinghua_input` VALUES (1,'穿黄工程',1,300,40,5355,265,1,1272,1,0,1,7,92.60,6,100,0.52,3.00,NULL,NULL,NULL,NULL,NULL,NULL),(2,'穿漳工程',1,100,30,1082,235,1,657,3,0,0,7,87.70,6,150,0.59,3.00,NULL,NULL,NULL,NULL,NULL,NULL),(3,'沙河渡槽',1,100,30,9050,320,4,1455,2,1,1,6,89.70,6,150,0.48,3.00,NULL,NULL,NULL,NULL,NULL,NULL),(4,'双洎河渡槽',1,100,50,1077,305,1,256,1,0,1,7,100.00,6,150,0.29,2.00,NULL,NULL,NULL,NULL,NULL,NULL),(5,'湍河渡槽',1,100,50,1030,350,3,194,2,0,1,6,94.80,8,150,0.52,3.00,NULL,NULL,NULL,NULL,NULL,NULL),(6,'北汝河倒虹吸',1,100,30,1482,315,1,76,3,1,0,6,92.90,8,150,0.41,3.00,NULL,NULL,NULL,NULL,NULL,NULL),(7,'穿沁河倒虹吸',1,100,40,1183,265,1,209,2,0,1,7,92.90,8,150,0.46,3.00,NULL,NULL,NULL,NULL,NULL,NULL),(8,'澧河渡槽',1,100,50,860,320,4,668,2,0,1,6,85.00,6,150,0.53,3.00,NULL,NULL,NULL,NULL,NULL,NULL),(11,'南沙河倒虹吸',1,100,40,4395,230,4,220,4,1,1,7,92.10,8,150,0.48,3.00,NULL,NULL,NULL,NULL,NULL,NULL);

#
# Structure for table "qinghua_input_1108"
#

DROP TABLE IF EXISTS `qinghua_input_1108`;
CREATE TABLE `qinghua_input_1108` (
  `ID` int(11) NOT NULL AUTO_INCREMENT,
  `jianzhuwu` varchar(255) DEFAULT NULL COMMENT '建筑物',
  `zonghefengxian` decimal(10,6) DEFAULT NULL COMMENT '综合风险',
  `jingtaifengxian` decimal(10,6) DEFAULT NULL COMMENT '静态风险',
  `dongtaifengxian` decimal(10,6) DEFAULT NULL COMMENT '动态风险',
  `gongchengdengji` int(11) DEFAULT NULL COMMENT '工程等级',
  `shejihongshui` int(11) DEFAULT NULL COMMENT '设计洪水标准/年',
  `zhutihnt` int(11) DEFAULT NULL COMMENT '主体混凝土强度/c',
  `jzwkuadu` int(11) DEFAULT NULL COMMENT '建筑物跨度/m',
  `sjshushuiliang` int(11) DEFAULT NULL COMMENT '设计输水流量/立方米/s',
  `fangshencuoshi` int(11) DEFAULT NULL COMMENT '防渗措施',
  `jianchaziqx` int(11) DEFAULT NULL COMMENT '检查质量缺陷/处',
  `jiagufangfa` int(11) DEFAULT NULL COMMENT '地基加固方法',
  `xinjishu` int(11) DEFAULT '0' COMMENT '新技术的采用',
  `yunyingli` int(11) DEFAULT '0' COMMENT '是否预应力',
  `dizhenliedu` int(11) DEFAULT NULL COMMENT '地震烈度',
  `yanshouyouliangdu` decimal(10,6) DEFAULT NULL COMMENT ' 验收优良度',
  `kangshendengji` int(11) DEFAULT NULL COMMENT '抗渗等级/w',
  `kangdongdengji` int(11) DEFAULT NULL COMMENT '抗冻等级',
  `hongfengliuliang` decimal(10,6) DEFAULT '4770.000000' COMMENT '洪峰流量',
  `dongrongkuailie` int(11) DEFAULT '0' COMMENT '冻融开裂:无/有',
  `chongshuashendu` decimal(10,6) DEFAULT NULL COMMENT '冲刷深度',
  `layingli` decimal(10,6) DEFAULT NULL COMMENT '最大拉应力/mpa',
  `shuiwei` decimal(10,0) DEFAULT NULL COMMENT '水位/m',
  `hongshui` decimal(10,6) DEFAULT NULL COMMENT '洪水指标',
  `dongrong` decimal(10,6) DEFAULT NULL COMMENT '冻融指标',
  `chongshua` decimal(10,6) DEFAULT NULL COMMENT '冲刷指标',
  `yingli` decimal(10,6) DEFAULT NULL COMMENT '应力指标',
  `anquancaisha` decimal(10,6) DEFAULT NULL COMMENT '安全采砂距离/m',
  `jiegouweixian` decimal(10,6) DEFAULT NULL COMMENT '结构危险点',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8;

#
# Data for table "qinghua_input_1108"
#

INSERT INTO `qinghua_input_1108` VALUES (1,'穿黄工程',NULL,0.480000,NULL,1,300,40,5355,265,1,1272,1,0,1,7,92.600000,8,150,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(2,'穿漳河工程',NULL,0.530000,NULL,1,100,30,1082,235,1,657,3,0,0,7,87.700000,6,150,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(3,'沙河渡槽',NULL,0.460000,NULL,1,100,30,9050,320,4,1455,2,1,1,6,89.700000,8,150,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(4,'双洎河渡槽',0.470000,0.410000,0.260000,1,100,50,1077,305,1,256,1,0,1,7,100.000000,8,150,4770.000000,0,5.500000,1.700000,110,0.500000,0.500000,0.000000,0.607000,NULL,NULL),(5,'瑞河渡槽',NULL,0.520000,NULL,1,100,50,1030,350,3,194,2,0,1,6,94.800000,8,150,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(6,'北汝河倒虹吸',NULL,0.290000,NULL,1,100,30,1482,315,1,76,3,1,0,6,92.900000,6,150,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(7,'穿沁河倒虹吸',NULL,0.480000,NULL,1,100,40,1183,265,1,209,2,0,1,7,92.900000,6,150,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(8,'澧河渡槽',NULL,0.590000,NULL,1,100,50,860,320,4,668,2,0,1,6,85.000000,6,150,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(9,'南沙河倒虹吸',NULL,0.520000,NULL,1,100,40,4395,230,4,220,4,1,1,7,92.100000,6,100,0.000000,0,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),(10,'安阳段',0.460000,0.520000,0.140000,1,100,30,963,245,1,242,3,0,0,8,87.500000,6,150,3700.000000,0,0.500000,0.650000,86,0.500000,0.500000,0.000000,0.310000,NULL,NULL);

#
# Structure for table "qinghua_test"
#

DROP TABLE IF EXISTS `qinghua_test`;
CREATE TABLE `qinghua_test` (
  `num` int(11) NOT NULL AUTO_INCREMENT,
  `rain` float(8,4) DEFAULT NULL COMMENT '清华测试表',
  `temperature` float(4,2) DEFAULT NULL,
  `other` int(5) DEFAULT NULL,
  `other2` int(5) DEFAULT NULL,
  PRIMARY KEY (`num`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8;

#
# Data for table "qinghua_test"
#

INSERT INTO `qinghua_test` VALUES (1,1.1111,1.11,1,1),(2,2.2220,2.20,2,2),(3,2.2222,2.22,2,2),(4,2.2222,2.22,2,2),(5,2.2222,2.22,2,2),(6,2.2222,2.22,2,2);

#
# Structure for table "qinghua_theme1"
#

DROP TABLE IF EXISTS `qinghua_theme1`;
CREATE TABLE `qinghua_theme1` (
  `id` int(1) NOT NULL,
  `chuanhuang` double(3,2) NOT NULL,
  `chuanzhanghe` double(3,2) NOT NULL,
  `shaheducao` double(3,2) NOT NULL,
  `shuangjihe` double(3,2) NOT NULL,
  `tuanhe` double(3,2) NOT NULL,
  `beiruhe` double(3,2) NOT NULL,
  `chuanqinhe` double(3,2) NOT NULL,
  `liheducao` double(3,2) NOT NULL,
  `caoheducao` double(3,2) NOT NULL,
  `nanshahe` double(3,2) NOT NULL,
  `shimenhe` double(3,2) NOT NULL,
  `baihedaohongxi` double(3,2) NOT NULL,
  `hutuohe` double(3,2) NOT NULL,
  `tanghe` double(3,2) NOT NULL,
  `minghe` double(3,2) NOT NULL,
  `yongdinghe` double(3,2) NOT NULL,
  `anyanghe` double(3,2) NOT NULL,
  `jiaoyiduan` double(3,2) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Data for table "qinghua_theme1"
#

INSERT INTO `qinghua_theme1` VALUES (0,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11,2.11);

#
# Structure for table "qinghua_theme2"
#

DROP TABLE IF EXISTS `qinghua_theme2`;
CREATE TABLE `qinghua_theme2` (
  `id` int(2) NOT NULL,
  `channelWater` float(5,2) DEFAULT NULL,
  `riverWater` float(5,2) DEFAULT NULL,
  `deepth` float(5,2) DEFAULT NULL,
  `deepthLocal` float(5,2) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Data for table "qinghua_theme2"
#


#
# Structure for table "qinghua_theme3"
#

DROP TABLE IF EXISTS `qinghua_theme3`;
CREATE TABLE `qinghua_theme3` (
  `id` int(6) NOT NULL AUTO_INCREMENT,
  `data` datetime(6) DEFAULT NULL COMMENT '日期+时间',
  `year` year(4) DEFAULT NULL COMMENT '年份',
  `month` int(2) DEFAULT NULL COMMENT '月份',
  `day` int(2) DEFAULT NULL COMMENT '日',
  `temperatureAve` float(5,3) DEFAULT NULL COMMENT '日平均温度',
  `temperatureMax` float(5,3) DEFAULT NULL COMMENT '日最大温度',
  `temperatureMin` float(5,3) DEFAULT NULL COMMENT '日最小温度',
  `humidityAve` float(6,3) DEFAULT NULL COMMENT '日平均湿度',
  `rainday` float(10,6) DEFAULT NULL COMMENT '日降雨量',
  `wind` double(5,3) DEFAULT NULL COMMENT '风速',
  `suntime` double(3,1) DEFAULT NULL COMMENT '日光照时间',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

#
# Data for table "qinghua_theme3"
#

