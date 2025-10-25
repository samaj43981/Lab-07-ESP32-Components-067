# Lab 7-2: Managed Component from GitHub URL Demo

## คำอธิบาย
การทดลองนี้แสดงการใช้งาน managed component จาก GitHub Repository
ใช้ `Sensors` component จาก https://github.com/APPLICATIONS-OF-MICROCONTROLLERS/Lab7_Components

## ผลลัพธ์ที่คาดหวัง
- แสดงข้อความการเริ่มต้น sensor จาก GitHub component
- แสดงข้อมูล temperature และ humidity ทุก 4 วินาที
- แสดงสถานะการทำงานของ sensor
- แสดงแหล่งที่มาของ component (GitHub Repository)

## ความแตกต่างจาก Lab 7-1
- Lab 7-1: ใช้ local component (ในเครื่อง)
- Lab 7-2: ใช้ managed component จาก GitHub URL

## การใช้งาน
1. เข้าไปในโฟลเดอร์ lab7-2_Managed_url_Component
2. รันคำสั่ง `idf.py build` (จะดาวน์โหลด component จาก GitHub อัตโนมัติ)
3. ทดสอบด้วย QEMU

---

## โจทย์ท้าทาย (Challenge)

### การทดลอง
- สร้าง Local Components (`Display`, `Led`) ภายในโปรเจค `lab7-2` ซึ่งมีการใช้งาน Managed Component (`lab7_components` จาก Github) อยู่แล้ว
- แก้ไข `CMakeLists.txt` หลักของโปรเจคโดยเพิ่ม `set(EXTRA_COMPONENT_DIRS "components")` เพื่อให้รู้จัก Local Components
- เปลี่ยนโค้ดใน `main` ให้เรียกใช้งานทุก components (ทั้ง Managed และ Local)
- ทำการ `idf.py fullclean && idf.py build`

### ผลการทดลองและสรุป
โปรเจคสามารถ **build ได้สำเร็จ** ซึ่งเป็นการยืนยันว่า **ESP-IDF สามารถรองรับการใช้งาน Managed Components และ Local Components ในโปรเจคเดียวกันได้**

ระบบ Build จะทำการ:
1.  ดาวน์โหลด Managed Component จาก `idf_component.yml` มาไว้ที่โฟลเดอร์ `managed_components`
2.  ค้นหา Local Component จากโฟลเดอร์ที่ระบุใน `EXTRA_COMPONENT_DIRS` (ในที่นี้คือ `components/`)
3.  นำ component ทั้งหมด (ทั้ง managed และ local) มา build รวมกับโค้ดหลักของโปรเจค

ดังนั้นคำตอบของคำถามที่ว่า **"ให้ผลลักษณะเดียวกับ component แบบ local หรือไม่"** คือ **ใช่** เราสามารถผสมผสานการใช้งาน component จากทั้งสองแหล่งได้ ทำให้โปรเจคมีความยืดหยุ่นสูง สามารถดึง component มาตรฐานจากภายนอกมาใช้ร่วมกับ component ที่พัฒนาขึ้นเองสำหรับโปรเจคโดยเฉพาะได้