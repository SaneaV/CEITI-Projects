package com.practice.ceiti.security.dao.repository;

import com.practice.ceiti.security.dao.model.Account;
import org.springframework.data.jpa.repository.JpaRepository;

public interface AccountRepository extends JpaRepository<Account, Long> {
    Account findOneByUsername(String username);
}