# Lab 7-1: Local Component Demo

## คำอธิบาย
การทดลองนี้แสดงการใช้งาน component ที่มีอยู่ในโฟลเดอร์ `components/Sensors/` ของ project


## สรุปคำสั่งที่ใช้ และผลลัพธ์ที่ได้

ในการทดลองนี้ พบปัญหา Docker container ไม่ทำงานและชื่อไม่ตรงกับในคู่มือ จึงต้องใช้คำสั่งเพื่อแก้ไขและ build project ดังนี้:

1.  **แก้ไขปัญหา Docker Network และ Container:**
    เนื่องจากพบปัญหาเกี่ยวกับ Docker network และชื่อ container ไม่ตรงกับที่คาดไว้ (เป็น `esp32-lab6-1` แทน `esp32-lab7`) จึงต้องทำการล้างค่าเก่าและสร้าง container ขึ้นมาใหม่
    ```bash
    # หยุดและลบ container และ network เก่า
    docker-compose down

    # สร้างและเริ่ม container ใหม่อีกครั้ง
    docker-compose up -d
    ```

2.  **Build โปรเจคภายใน Docker Container:**
    ใช้ `docker exec` เพื่อเข้าไปรันคำสั่ง build ภายใน container ที่ถูกต้อง (`esp32-lab6-1`)
    ```bash
    docker exec esp32-lab6-1 bash -c "cd /project/lab7-1_Managed_Local_Component && . /opt/esp/idf/export.sh && idf.py set-target esp32 && idf.py build"
    ```

**ผลลัพธ์:**

โปรเจคสามารถ build ได้สำเร็จเรียบร้อย โดยผลลัพธ์ส่วนท้ายของการ build แสดงดังนี้:

```
lab7-1.bin binary size 0x27fb0 bytes. Smallest app partition is 0x100000 bytes. 0xd8050 bytes (84%) free.

Project build complete. To flash, run:
 idf.py flash
```

ซึ่งหมายความว่าไฟล์ `lab7-1.bin` ได้ถูกสร้างขึ้นและพร้อมสำหรับการ flash ลงอุปกรณ์ ESP32 แล้ว

---

## โจทย์ท้าทาย (Challenge)

### 1. สร้าง component ชื่อ `Display` และ `Led`
- สร้างโฟลเดอร์ `components/Display` และ `components/Led`
- นำไฟล์ `.c` และ `.h` ที่เกี่ยวข้องจากใบงานที่ 6 มาใส่
- สร้างไฟล์ `CMakeLists.txt` สำหรับแต่ละ component เพื่อให้ระบบ build รู้จัก

### 2. นำโค้ดจาก main.c ในใบงานที่ 6 มาใช้
- แก้ไขไฟล์ `main/lab7-1.c` ให้เป็นโค้ดจากใบงานที่ 6 ซึ่งมีการเรียกใช้ `sensor`, `display`, และ `led` component

### สรุปคำสั่งที่ใช้ และผลลัพธ์ที่ได้
หลังจากเตรียมไฟล์ component และแก้ไขไฟล์ main แล้ว พบว่า build ในครั้งแรกล้มเหลวเนื่องจาก build system ไม่เจอ component ใหม่ จึงต้องใช้คำสั่ง `idf.py fullclean` เพื่อล้างค่าเก่าและ build โปรเจคใหม่

```bash
docker exec esp32-lab6-1 bash -c "cd /project/lab7-1_Managed_Local_Component && . /opt/esp/idf/export.sh && idf.py fullclean && idf.py build"
```

**ผลลัพธ์:**
โปรเจคสามารถ build ได้สำเร็จ โดยมีการนำ `Display` และ `Led` component เข้ามารวมด้วยอย่างถูกต้อง ผลลัพธ์สุดท้ายได้เป็นไฟล์ `lab7-1.bin` ขนาด 0x287e0 bytes ซึ่งใหญ่กว่าเดิมเล็กน้อยเนื่องจากมีโค้ดของ 2 components เพิ่มเข้ามา

```
lab7-1.bin binary size 0x287e0 bytes. Smallest app partition is 0x100000 bytes. 0xd7820 bytes (84%) free.

Project build complete. To flash, run:
 idf.py flash
```