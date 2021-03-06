package DesignMode.DesignModel.Visitor;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by han on 2017/3/9.
 */
public class Client {
    public static void main(String[] args) {
        IVisitor visitor = new Visitor();
        for (Employee emp : mockEmployee()) {
            emp.accept(visitor);
        }
        System.out.println("工资总额:"+visitor.getTotalSalary());
    }

    public static List<Employee> mockEmployee() {
        List<Employee> empList = new ArrayList<Employee>();
        CommonEmployee zhangsan = new CommonEmployee();
        zhangsan.setJob("java码农 屌丝到死");
        zhangsan.setName("张三");
        zhangsan.setSalary(1800);
        zhangsan.setSex(Employee.MALE);
        empList.add(zhangsan);
        CommonEmployee lisi = new CommonEmployee();
        lisi.setJob("页面美工 审美素质太不行了");
        lisi.setName("李四");
        lisi.setSalary(1900);
        lisi.setSex(Employee.FEMALE);
        empList.add(lisi);
        Manager wangWu = new Manager();
        wangWu.setName("王五");
        wangWu.setPerformance("大佬 就是天生的 你不用想");
        wangWu.setSalary(18750);
        wangWu.setSex(Employee.MALE);
        empList.add(wangWu);
        return empList;
    }
}
